#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+4,M=1e6+6;
long long n,m,k,h[N],cnt=0,dd[15][N],c[15],cc[15];
struct edge
{
	long long v,w,next;
}e[M*2];
void add(long long u,long long v,long long w)
{
	e[++cnt]={v,w,h[u]};
	h[u]=cnt;
}
struct node 
{
	long long id,d;
	bool operator<(const node &o)const 
	{
		return d>o.d;
	}
};
priority_queue<node>q;
long long p[N],d[N];
void prim()
{
	long long ans=0;
	q.push({1,0});d[1]=0;
	while(!q.empty())
	{
		node t=q.top();q.pop();
		long long u=t.id;
		if(p[u]==1)continue;
		ans+=d[u];
		p[u]=1;
		for(long long i=h[u];i!=-1;i=e[i].next)
		{
			long long v=e[i].v,w=e[i].w;
			if(p[v]==0)
			{
				if(d[v]>w)
				{
					d[v]=w;
					q.push({v,w});
				}
			}
		}
		for(long long i=1;i<=k;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(d[j]>c[i]+dd[i][j]+dd[i][u])
				{
					d[j]=c[i]+dd[i][j]+dd[i][u];
					q.push({j,d[j]});
				}
			}
		}
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(d,0x3f,sizeof d);
	memset(h,-1,sizeof h);
	for(long long i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);add(v,u,w);
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1;j<=n;j++)
		{
			cin>>dd[i][j];
		}
	}
	prim();
	return 0;
}

