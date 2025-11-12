#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=INT_MAX;
map<int,bool>vi;
map<int,bool>vis;
struct z
{
	int v,w;
};
vector<z>g[10001];
bool pd()
{
	for(int i=1;i<=n;i++) if(vis[i]==0) return 0;
	return 1;
}
void dfs(int u,int s,int fa)
{
	if(pd())
	{
		ans=min(ans,s);
		return ;
	}
	if(s>ans) return ;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].v;
		if(v!=fa&&vis[v]==0)
		{
			vis[v]=1;
			if(vi[u]) dfs(v,s,u);
			else dfs(v,s+g[u][i].w,u);
			vis[v]=0;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		int p;
		cin>>p;
		vi[j]=1;
		for(int j=1;j<=n;j++)
		{
			int o;
			cin>>o;
		}
	}
	vis[1]=1;
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
