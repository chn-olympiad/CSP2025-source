#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1005][1005];
int b[11];
int c[11][1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	}
	return 0;
}

