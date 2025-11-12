#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node
{
	int nxt,to;
	int val;
}e[N];
int head[N];
int num;
int n,m,k;
int u,v,w;
int cmp(node a,node b)
{
	return a.val<b.val;
}
void star(int u,int v,int w)
{
	e[++num].to=v;
	e[num].nxt=head[u];
	e[num].val=w;
	head[u]=num;
}
int d[N];
int co[N];
int c[N];
bool vis[N];
priority_queue<pair<int,int> >q;
void dj(int s)
{
	for(int i=0;i<=N;i++)
	{
		vis[i]=0;
		d[i]=1e9;
	}
	d[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[s]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			int w=e[i].val;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push(make_pair(-d[v],v));
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		star(u,v,w);
		star(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&co[i]);
		}
	}
	//sort(e+1,e+m+1,cmp);
	dj(1);
	printf("%d",d[n]);
}
