#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
const int NMAX=2e6+10;
int n,m,k,cnt,u,v,w;
int head[N];
int a[20];
int dis[N],vis[N],ans;
struct node
{
	int nxt,to,w;
}ed[NMAX];
void add(int u,int v,int w)
{
	ed[++cnt].nxt=head[u];
	head[u]=cnt;
	ed[cnt].to=v;
	ed[cnt].w=w;
}
priority_queue<pair<int,int>> q;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=n+1;i<=n+k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			add(i,j,w);
			add(j,i,w);
		}
	}
	q.push({0,1});
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=ed[i].nxt)
		{
			int v=ed[i].to,w=ed[i].w;
			if(v>n)
			{
				if(dis[v]>dis[u]+w+a[v])
				{
					dis[v]=dis[u]+w+a[v];
					ans+=(dis[v]-dis[u]);
					q.push({-dis[v],v});
				}
			}
			else
			{
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					ans+=(dis[v]-dis[u]);
					q.push({-dis[v],v});
				}
			}
		}
	}
	// for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
	// cout<<'\n';
	cout<<ans;
	return 0;
}