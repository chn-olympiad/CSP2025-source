#include<cstdio>
#include<algorithm>
using namespace std;
long long head[1000005],nxt[1000005],to[1000005],val[1000005],tot=0;
long long a[1000005];
long long dis[15][1000005];
long long fa[1000005];
struct edge
{
	long long u,v,w;
}e[4000005];
void add(long long u,long long v,long long w)
{
	tot++;
	nxt[tot]=head[u];
	to[tot]=v;
	val[tot]=w;
	head[u]=tot;
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
long long find(long long x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++)
	{
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[++tot]=(edge){u,v,w};
	}
	for(long long i=1;i<=k;i++)
	{
		scanf("%lld",&a[n+i]);
		for(long long j=1;j<=n;j++)
		{
			scanf("%lld",&dis[i][j]);
		}
	}
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(e+1,e+tot+1,cmp);
	for(long long i=1;i<=tot;i++)
	{
		long long u=find(e[i].u),v=find(e[i].v);
		if(u==v)
		{
			continue;
		}
		ans+=e[i].w;
		fa[u]=v;
	}
	printf("%lld",ans);
	return 0;
}
