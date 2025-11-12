#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e4+5,MAXM=1e6+5;

struct edge{
	int u,v,w;
}edges[MAXM];

bool cmp(edge e1,edge e2){
	return e1.w<e2.w;
}

int n,m,k;

int father[MAXN];
int find(int u){
	if (father[u]!=u) father[u]=find(father[u]);
	return father[u];
}
//int g[MAXN][MAXN];

int ks(){
	int sum=0;
	sort(edges+1,edges+m+1,cmp);
	for (int i=1;i<=n-1;i++){
		int u=edges[i].u,v=edges[i].v,w=edges[i].w;
		if (find(u)!=find(v)){
			father[u]=v;
			sum+=w;
		}
	}
	return sum;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	dfs(k,"");
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		//g[u][v]=w;
		//g[v][u]=w;
		edges[i]={u,v,w};
	}
	for (int u=1;u<=n;u++){
		father[u]=u;
	}
	// 暂不考虑未城市化村庄的影响  
	// 克鲁斯卡尔算法 
	cout<<ks();
	return 0;
}
