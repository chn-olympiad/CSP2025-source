#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll v,w;
};
ll n,m,k,minn=1e18,vis[10001],xc[11],fa[10001];
vector<node>g[10001];
void dfs(ll x,ll s,ll ss)
{
	if(ss>minn)return;
	if(s==n)minn=min(minn,ss);
	if(s>n)return;
	for(ll i=0;i<g[x].size();i++)
	{
		ll v=g[x][i].v;
		if(!vis[v])
		{
			vis[v]=1;
			if(v>n)dfs(v,s+1,ss+g[x][i].w+xc[v-n]);
			else dfs(v,s+1,ss+g[x][i].w);
			vis[v]=0;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=2*n;i++)
	{
		g[0].push_back({i,0});
	}
	for(ll i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(ll i=1;i<=k;i++)
	{
		ll x,w;
		cin>>x;
		xc[i]=x;
		for(ll j=1;j<=n;j++)
		{
			cin>>w;
			g[n+i].push_back({i,w});
			g[i].push_back({n+i,w});
		}
	}
	dfs(0,0,0);
	cout<<minn;
	return 0;
}
