#include<bits/stdc++.h>
using namespace std;
int n,m,k,y,s[11],g[1001][1001];
vector<int>c[1001];
bool h[1001],o[1001][1001];
int dfs(int x){
	int k=1e8;
	bool f=0;
	for(int i=0;i<c[x].size();i++){
		if(!h[c[x][i]]){
			f=1;
			h[c[x][i]]=1;
			int z=g[x][c[x][i]]+dfs(c[x][i]);
			if(k>z){
				k=z;
			}
			h[c[x][i]]=0;
		}
	}
	if(!f)
		return 0;
	return k;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int v,u,w;
		cin>>v>>u>>w;
		c[v].push_back(u);
		c[u].push_back(v);
		g[u][v]=w;
		g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int s;
		cin>>s;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			c[n+i].push_back(j);
			c[j].push_back(n+i);
			g[j][n+i]=a;
			g[n+i][j]=a;
		}
	}
	cout<<dfs(1);
	return 0;
}  
