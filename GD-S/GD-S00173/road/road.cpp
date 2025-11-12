#include<cstdio>
#include<algorithm>
int fa[10011];
int Find(const int &a)
{
	if(a==fa[a])return a;
	return fa[a]=Find(fa[a]);
}
struct Bian
{
	int u,v,w;
}g[1100001];
bool cmp(const Bian& a,const Bian& b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,s=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
	for(int i=1;i<=k;i++)
	{
		int c;
		scanf("%d",&c);
		if(c==0)s++;
		for(int j=1,w;j<=n;j++)
		{
			scanf("%d",&w);
			if(c==0)
			{
				m++;
				g[m].u=j;
				g[m].v=n+i;
				g[m].w=w;
			}
		}
	}
	n+=s;
	std::sort(g+1,g+1+m,cmp);
	long long ans=0;
	for(int i=1,cnt=1;i<=m&&cnt<n;i++)
	{
		if(Find(g[i].u)==Find(g[i].v))continue;
		fa[g[i].v]=fa[g[i].u];
		cnt++;
		ans+=g[i].w;
	}
	printf("%lld",ans);
	return 0;
}
