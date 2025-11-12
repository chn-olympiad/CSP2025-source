#include<bits/stdc++.h>
using namespace std;
const int maxn=10015;
bool vis[maxn],vis2[15];
vector< pair<int,int> > g[maxn];
int n,m,k,dis[maxn],c[15];
long long prim(int x)
{
	long long ans=0;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=k;i++)
	{
		vis[n+i]=vis2[i];
		if(vis2[i])dis[i+n]=0;
	}
	priority_queue< pair<int,int> > q;
	q.push(make_pair(0,x));
	dis[x]=0;
	while(!q.empty())
	{
		pair<int,int> now=q.top();
		q.pop();
		int w=0-now.first,u=now.second;
		if(dis[u] < w)continue;
		ans+=1ll*w;
		vis[u]=true;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first;
			if(!vis[v]&&dis[v]>g[u][i].second)
			{
				dis[v]=g[u][i].second;
				q.push(make_pair(0-dis[v],v));
			}
		}
	}
	return ans;
}
long long dfs()
{
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<=(1<<k)-1;i++)
	{
		long long sum=0;
		for(int j=1;j<=k;j++)
		{
			if((i>>(j-1))%2==1)vis2[j]=false,sum+=1ll*c[j];
			else vis2[j]=true;
		}
		ans=min(ans,sum+prim(1));
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			g[i+n].push_back(make_pair(j,w));
			g[j].push_back(make_pair(i+n,w));
		}
	}
	int ans=dfs();
	cout<<ans;
	return 0;
}
