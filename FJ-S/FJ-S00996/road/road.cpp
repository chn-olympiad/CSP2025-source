#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
long long n,m,k,f[N][N],v[N],f2[20],ans; 
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			f[i][j]=INT_MAX;
		}
	}
	for(int i=1; i<=m; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		f[u][v]=f[v][u]=c;
	}
	for(int i=1; i<=k; i++) {
		cin>>f2[i];
		for(int j=1; j<=n; j++) {
			int x;
			cin>>x;
			f[n+i][j]=f[j][n+i]=f2[i]+x;
		}
	}
	for(int l=1; l<=n; l++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i!=j&&i!=l&&j!=l&&f[i][j]!=0) {
					f[j][i]=f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout<<f[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			ans+=f[i][j];
		}
	}
	cout<<ans;
	return 0;
}
