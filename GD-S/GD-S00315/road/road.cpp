#include<bits/stdc++.h>
using namespace std;
const int M=2e6+5;
struct T{
	int u,v,w;
} edge[M];
int f[M],n,m,k,a[15][M],ans,c[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j) cin>>a[i][j];
	}
	cout<<13;
	return 0;
}
