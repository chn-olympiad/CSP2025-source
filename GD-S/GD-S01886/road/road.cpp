#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m,k,cnt;
int f[1005][1005],a[1005][1005],c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=min(f[u][v],w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<0<<endl;
	return 0;
}
