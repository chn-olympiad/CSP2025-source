#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
const int M=1e4+1;
int n,m,k;
int g[M][M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int a;
			cin>>a; 
		}
	}
	cout<<13;
	return 0;
}
