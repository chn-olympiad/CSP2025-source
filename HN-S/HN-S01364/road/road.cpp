#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int n,m,k,w[maxn][maxn];
int c[maxn],a[maxn][maxn];
int vis[maxn],ans=-1;
vector<int>q[maxn];
void dfs(int u,int sum){
	vis[u]=1;
	ans=max(ans,sum);
	for(int i=0;i<q[u].size();i++){
		int v=q[u][i];
		if(vis[v]==1)continue;
		vis[v]=1;
		dfs(v,sum+w[u][v]);
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		cin>>w[u][v];
		w[v][u]=w[u][v];
		q[u].push_back(v);
		q[v].push_back(u);
	}
//	int p0;
//	for(int i=1;i<=k;i++){
//		cin>>c[i];
//		for(int j=1;j<=n;j++){
//			cin>>a[i][j];
//			if(a[i][j]==0)p0=j;
//		}
//		for(int j=1;j<=n;j++){
//			w[p0][j]=min(a[i][j],w[p0][j]);
//		}
//	}
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
//long long ·¶Î§

