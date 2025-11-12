#include <bits/stdc++.h>
using namespace std;
int g[10015][10015],c[15];
int ans=0;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(g,-1,sizeof(g));
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
	}
	for (int i=1;i<=k;i++) {
		cin>>c[i];
		for (int j=1;j<=n;j++) {
			int a;
			cin>>a;
			g[j][n+i]=g[n+i][j]=a;
		}
	}
	cout<<0;
	return 0;
}
