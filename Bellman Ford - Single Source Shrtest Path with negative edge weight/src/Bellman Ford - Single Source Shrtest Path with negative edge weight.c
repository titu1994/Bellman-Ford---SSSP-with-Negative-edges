/*
 ============================================================================
 Name        : Bellman.c
 Author      : Somshubra Majumdar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <ctype.h>


typedef struct {
    int u, v, w;
} Edge;

int n; /* the number of nodes */
int e; /* the number of edges */
Edge edges[1024]; /* large enough for n <= 2^5=32 */
int d[32]; /* d[i] is the minimum distance from node s to node i */

#define INFINITY 10000

void printDist() {
    int i;

    printf("Distances:\n");

    for (i = 0; i < n; ++i)
        printf("to %d\t", i + 1);
    printf("\n");

    for (i = 0; i < n; ++i)
        printf("%d\t", d[i]);

    printf("\n\n");
}

void bellman_ford(int s) {
    int i, j;

    for (i = 0; i < n; ++i)
        d[i] = INFINITY;

    d[s] = 0;

    for (i = 0; i < n - 1; ++i)
        for (j = 0; j < e; ++j)
            if (d[edges[j].u] + edges[j].w < d[edges[j].v])
                d[edges[j].v] = d[edges[j].u] + edges[j].w;
}

void createWeightedGraph(int a[n][n],int n){
	int i,j,w,ch;
	char x,y;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			a[i][j] = 0;
		}
	}

	do{
		fflush(stdin);

		printf("Enter the edge names : ");
		scanf("%c%c", &x,&y);

		x = toupper(x);
		y = toupper(y);

		printf("Enter the weight of this edge : ");
		scanf("%d", &w);

		a[x-65][y-65] = w;
		a[y-65][x-65] = w;

		printf("Enter 1 to continue adding edges : ");
		scanf("%d", &ch);

	}while(ch == 1);
}

int main() {
    int i, j;
    int w;
    int n;
    int a[10][10] = {{0}};

    printf("Enter the number of edges : ");
    scanf("%d", &n);
    e = 0;

    createWeightedGraph(a,n);

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j) {
            w = a[i][j];
            if (w != 0) {
                edges[e].u = i;
                edges[e].v = j;
                edges[e].w = w;
                ++e;
            }
        }

    /* printDist(); */
    bellman_ford(0);
    printDist();

    return 0;
}
