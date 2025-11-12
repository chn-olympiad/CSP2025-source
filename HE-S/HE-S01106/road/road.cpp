#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct ed{
	int to,next,w;
}e[M<<1];
struct edge{
	int u,v,w;
}edges[M<<1];
int n,m,k,maxx,idx;
int c[N],g[11][N],fa[N],head[N],sum[N],flag[N],ch[N],last[N],dep[N],cnt[N];
long long ans;
void add(int u,int v,int w)
{
	e[++idx].to=v;
	e[idx].next=head[u];
	e[idx].w=w;
	head[u]=idx;
}
bool cmpp(edge a1,edge b1)
{
	return a1.w<b1.w;
}
int findd(int x)
{
	if(fa[x]!=x)
		fa[x]=findd(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	fa[y]=x;
}
void dfs(int u,int faa)
{
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==faa)
			continue;
		dep[v]=dep[u]+1;
		last[v]=sum[v]=e[i].w;
		dfs(v,u);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		maxx=max(maxx,c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	}
	sort(edges+1,edges+m+1,cmpp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int r1=findd(edges[i].u),r2=findd(edges[i].v),w=edges[i].w;
		if(r1!=r2)
		{
			merge(r1,r2);
			add(edges[i].u,edges[i].v,w);
			add(edges[i].v,edges[i].u,w);
			ans+=w;
		}
	}
	if(!k)
		printf("%lld",ans);
	else
	{
		dfs(1,0);
		for(int i=2;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j || dep[i]<dep[j])
					continue;
				for(int t=1;t<=k;t++)
					if(sum[i]>g[t][i]+g[t][j])
						flag[i]=t,sum[i]=g[t][i]+g[t][j];
			}
		for(int i=2;i<=n;i++)
			ch[flag[i]]+=last[i]-sum[i];
		for(int i=1;i<=k;i++)
			if(ch[i]>c[i])
				ans+=c[i]-ch[i];
		printf("%lld",ans);
	}
	return 0;
}
