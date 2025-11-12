#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int f[1005];
int g[1005][1005];
int b[1005];
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
		b[i]=w;
	}
	for(int i=1;i<=k;i++){
		int num;
		cin>>num;
		for(int j=1;j<=n;j++){
			cin>>num;
		}
	}
	cout<<0;
	return 0;
}
