#include<bits/stdc++.h>
using namespace std;
const int M=100010;
struct Edge{
	int u,v;
	int cost;
};
int n,m,k;
Edge s_edge[M*10];
Edge edge[M*20];
int s_graph[M][M];
int graph[M][M];
void create(){
	scanf("%d %d %d",&n,&m,&k);
	Edge e;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) s_graph[i][j]=-1;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&e.u,&e.v,&e.cost);
		s_edge[i]=e;
		s_graph[e.u][e.v]=e.cost;
		s_graph[e.v][e.u]=e.cost;
	}
}
int main(){
	create();
	return 0;
}
