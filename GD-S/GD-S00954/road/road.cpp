#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e4+100,M=3e6+100;

struct node
{
	int x;
	ll d;
	const operator < (const node &a) const{ return a.d>d; }
};

struct edge
{
	int x,y,z,nxt;
}e[M];

int head[N],cnt=0,n,m,k,c[15],a[15][N];
ll dis[N],use[M];
bool vis[N],build[15];
priority_queue<node> q;

inline void dj(int s)
{
	dis[1]=0;
	for(int i=2;i<=n;i++)
		dis[i]=LLONG_MAX;
	q.push({s,0});
	while(q.size())
	{
		int u=q.top().x;
		q.pop();
		if(vis[u]==true)
			continue;
		vis[u]=true;
		for(int i=head[u];i;i=e[i].nxt)
		{
			ll v=e[i].y,w=e[i].z;
			if(dis[v]>dis[u]+w)
			{
				//cout<<'@'<<dis[v]<<' '<<dis[u]+w<<'\n';
				dis[v]=dis[u]+w;
				q.push({ v,dis[v] });
			}
		}
	}
}

inline void add(int u,int v,int w)
{
	e[++cnt]={ u,v,w,head[u] };
	head[u]=cnt;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	memset(head,0,sizeof(head));
	memset(vis,false,sizeof(vis));
	memset(use,false,sizeof(use));
	memset(build,false,sizeof(build));
	memset(use,0,sizeof(use));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	dj(1);
	//kÀ„∑®‘ı√¥–¥£ø
	ll sum=0;
	for(int i=1;i<=n;i++)
		 sum+=dis[i];
	cout<<sum;
	return 0;
} 











