#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000005
#define M 10005
int n,m,k,c[N],g[M][M],ans,a[M][M];
signed main(){
	freopen("road.in","r",stdin);
  	freopen("road.out","w",stdout);
	memset(g,-1,sizeof(g));
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)cin>>a[i][j];
	}
	for(int i=1;i<n;++i){
		int mi=0x3f3f3f3f;
		for(int j=1;j<=k;++j)mi=min(mi,a[j][i]+a[j][i+1]);
		if(g[i][i+1]==-1)ans+=mi;
		else ans+=min(mi,g[i][i+1]);
	}
	cout<<ans;
	return 0;
}
