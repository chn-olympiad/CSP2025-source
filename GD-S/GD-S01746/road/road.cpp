#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a[1005][1005],b[15],c[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	cout<<a[1][n];
	return 0;
}
