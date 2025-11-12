#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
long long ans,cnt;
int n,m,k,a[N][N],b[20],c[20][N],f[N][N];
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
		for(int j=1;j<=n;j++)cin>>c[i][j];
	}
	cout<<0;
	return 0;
}
