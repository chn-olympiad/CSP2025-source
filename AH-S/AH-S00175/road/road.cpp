#include<bits/stdc++.h>
using namespace std;
//~ #define int long long

int n,m,k,fa[10005],c[15],a[15][10005];
int adj[10005][10005],dp[10005][10005];
bool g[10005],vis[10005];

int fat(int x){
	if(fa[x]==x)return x;
	return fat(fa[x]);
}



signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		adj[u][v] = adj[v][u] = w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(i!=j&&c[i]+a[i][j]<adj[i][j])g[i]=1;
		}
	}
	memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=1;i<=n;i++)dp[i][i]=0;
	int ans=0,cnt=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				dp[i][j]=min({dp[i][j],dp[i][k]+dp[k][j],g[i]?a[i][j]:INT_MAX});
				if(dp[i][j]==a[i][j]&&!vis[i])ans+=c[i],vis[i]=1,cnt++;
			}
	for(int i=1;i<=n;i++)ans+=dp[1][i];
	cout<<ans;
	return 0;
}
