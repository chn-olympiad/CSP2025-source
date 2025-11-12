#include<bits/stdc++.h>
using namespace std;
int c[12],dis[10002];
int a[10002][10002],g[12][10002];
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) a[i][j]=a[j][i]=2e9;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			for(int o=1;o<j;o++) a[j][o]=min(a[j][o],g[i][j]+g[i][o]);
		}
	}
	int maxx=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				maxx=max(maxx,a[i][j]);
			}
		}
	}
	cout<<maxx;
	return 0;
}

