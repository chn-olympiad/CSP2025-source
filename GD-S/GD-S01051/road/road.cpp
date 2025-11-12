#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+101;
struct Edge
{
	int to, dis, nxt;
}e[N];
struct Node
{
	int dis, id;
	bool operator < (const Node &x)
	{
		return x.dis>dis;
	}
};
int head[N], tot, dis[N], c[11];
bool vis[N], build[N];
void addedge(int u, int v, int w)
{
	e[++tot]=(Edge){v, w, head[u]};
	head[u]=tot;
}
void spfa(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(build, false, sizeof(build));
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(!(q.empty()))
	{
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].dis)
			{
				dis[v]=dis[u]+e[i].dis;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
}
int Dijkstra(int n, int s)
{
	memset(dis, -1, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(build, false, sizeof(build));
	queue<Node> q;
	q.push((Node){0, s});
	int res=0;
	dis[s]=0;
	while(!(q.empty()))
	{
		int u=q.front().id, t=q.front().dis;
		q.pop();
		if(t>dis[u])
			continue;
		vis[u]=false;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(!(build[v]))
			{
				if(v<n&&(dis[v]==-1)||(dis[v]>dis[u]+e[i].dis))
				{
					dis[v]=dis[u]+e[i].dis;
					res+=e[i].dis;
					build[v]=true;
					if(!vis[v])
					{
						q.push((Node){dis[v], v});
						vis[v]=true;
					}
				}
				else
				{
					if((dis[v]==-1)||(dis[v]>dis[u]+e[i].dis+c[v-n]))
					{
						dis[v]=dis[u]+e[i].dis+c[v-n];
						res+=e[i].dis+c[v-n];
						build[v]=true;
						if(!vis[v])
						{
							q.push((Node){dis[v], v});
							vis[v]=true;
						}
					}
				}		
			}
			else if((dis[v]==-1)||(dis[v]>dis[u]))
			{
				dis[v]=dis[u];
				if(!vis[v])
				{
					q.push((Node){dis[v], v});
					vis[v]=true;
				}
			}
		}
	}
	return res;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k, ans=INT_MAX;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		addedge(u, v, w);
		addedge(v, u, w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int m;
			cin>>m;
			addedge(n+i, j, m);
			addedge(j, n+i, m);
		}
	}
	for(int i=1;i<=n;i++)
		ans=min(Dijkstra(n, i), ans);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
