#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v;
int w;
int f[1100][1200];
int ans;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=1000; i++) {
		for(int j=1; j<=1000; j++) {
			f[i][j]=1e9;
		}
	}
	for(int i=1; i<=m; i++) {
		cin>>u>>v>>w;
		f[u][v]=min(f[u][v],w);
		f[v][u]=min(f[v][u],w);
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				f[i][j]=min(f[i][k],f[k][j]);
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			ans+=f[i][j];
		}
	}
	cout<<ans;
	return 0;
}
