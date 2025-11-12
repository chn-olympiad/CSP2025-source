#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=12;
struct edge
{
	long long u,v,w;
	bool operator<(const edge x) const
	{
		return w>x.w;
	}
};
priority_queue<edge> q;
int n,m,k,cnt;
long long ans;
int c[K],vis[N];
long long dis[K][N],sum[K];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>dis[i][j];
		}
	}
	while(cnt<n)
	{
		auto x=q.top();
		q.pop();
		long long u=x.u,v=x.v,w=x.w;
		if(vis[u]&&vis[v]) continue;
		if(!vis[u]) cnt++;
		if(!vis[v]) cnt++;
		vis[u]=vis[v]=1;
		ans+=w;
		for(int i=1;i<=k;i++)
		{
			sum[i]+=min(dis[i][u]+dis[i][v],w);
		}
	}
	for(int i=1;i<=k;i++)
	{
		ans=min(ans,sum[i]+c[i]); 
	}
	cout<<ans; 
	return 0;
}
