#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
struct node{
	int u,v;
	long long w;
}a[3000010],d[3000010];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int n,m,k;
int vis[20],fa[10050];
long long b[20][10010],c[20],ans=INF;
void init()
{
	for(int i=1;i<=n+10;++i)fa[i]=i;
}
int fd(int x)
{
	if(fa[x]!=x)return fa[x]=fd(fa[x]);
	return x;
}
void he(int x,int y)
{
	fa[fd(x)]=fa[fd(y)];
}
bool check(int x,int y)
{
	return fd(x)==fd(y);
}
void dfs(int ceng)
{
	if(ceng==k+1)
	{
		int tot=0;
		long long sum=0;
		for(int i=1;i<=m;++i)d[i]=a[i];
		for(int i=1;i<=k;++i)
		{
			if(vis[i])
			{
				for(int j=1;j<=n;++j)
				{
					++tot;
					d[tot+m].u=i+n;
					d[tot+m].v=j;
					d[tot+m].w=b[i][j];
				}
				sum+=c[i];
			}
		}
		sort(d+1,d+m+tot+1,cmp);
		init();
		for(int i=1;i<=m+tot;++i)
		{
			if(!check(d[i].u,d[i].v))
			{
				he(d[i].u,d[i].v);
				sum+=d[i].w;
			}
		}
		ans=min(ans,sum);
		return;
	}
	vis[ceng]=1;
	dfs(ceng+1);
	vis[ceng]=0;
	dfs(ceng+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	int flagA=1;
	for(int i=1;i<=k;++i)
	{
		scanf("%lld",&c[i]);
		if(c[i])flagA=0;
		for(int j=1;j<=n;++j)
		{
			scanf("%lld",&b[i][j]);
		}
	}
	if(flagA)
	{
		int tot=0;
		long long sum=0;
		for(int i=1;i<=m;++i)d[i]=a[i];
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=n;++j)
			{
				++tot;
				d[tot+m].u=i+n;
				d[tot+m].v=j;
				d[tot+m].w=b[i][j];
			}
		}
		sort(d+1,d+m+tot+1,cmp);
		init();
		for(int i=1;i<=m+tot;++i)
		{
			if(!check(d[i].u,d[i].v))
			{
				he(d[i].u,d[i].v);
				sum+=d[i].w;
			}
		}
		printf("%lld",sum);
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
//	if(k==0)
//	{
//		for(int i=1;i<=n;++i)fa[i]=i;
//		for(int i=1;i<=m;++i)
//		{
//			
//		}
//	}
}

