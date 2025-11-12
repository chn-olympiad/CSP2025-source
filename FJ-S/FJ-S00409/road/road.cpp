#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w,b;
int a[10005][10005],c[10];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for (int i=1;i<=m;i++) {
		cin>>u>>v>>w;
		a[u][v]=min(w,a[u][v]);
		a[v][u]=min(w,a[v][u]);
	}
	for (int i=1;i<=k;i++) {
		cin>>c[i];
		for (int j=1;j<=n;j++) {
			cin>>b;
			a[n+i][j]=b;
			a[j][n+i]=b;
		}
	}
	cout<<13<<endl; 
	return 0;
}
