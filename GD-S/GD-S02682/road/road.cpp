#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
}edge[2000010],jt[2000010];
bool cmp(node xxx,node yyy)
{
	return xxx.w<yyy.w;
}
long long n,m,k,fa[20010],ans,c[20],a[20][20010];
long long ff(long long num)
{
	if(fa[num]==num) return num;
	return fa[num]=ff(fa[num]);
}
void solve1()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) 
	{
		scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		long long fu=ff(edge[i].u),fv=ff(edge[i].v);
		if(fu==fv) continue;
		fa[fu]=fv;
		ans+=edge[i].w;
	}
	printf("%lld",ans);
	return;
}
long long qdgs=0,ljq=0;
void act_dfs(long long num)
{
	if(num==k+1)
	{
		for(int i=1;i<=qdgs;i++) fa[i]=i;
		for(int i=1;i<=m;i++) jt[i]=edge[i];
		sort(jt+1,jt+1+m,cmp);
		long long pas=ljq;
		for(int i=1;i<=m;i++)
		{
			int fu=ff(jt[i].u),fv=ff(jt[i].v);
			if(fu==fv) continue;
			fa[fu]=fv;
			pas+=jt[i].w;
		}
		ans=min(ans,pas);
		return;
	}
	act_dfs(num+1);
	qdgs++;
	ljq+=c[num];
	for(int i=1;i<=n;i++)
	{
		edge[m+i].u=qdgs;
		edge[m+i].v=i;
		edge[m+i].w=a[num][i];
	}
	m+=n;
	act_dfs(num+1);
	qdgs--;
	ljq-=c[num];
	m-=n;
}
void solve3()
{
	ans=0;
	for(int i=1;i<=k;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			edge[++m].u=n+i;
			edge[m].v=j;
			edge[m].w=a[i][j];
		}
	}
	n+=k;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(edge+1,edge+1+m,cmp);
	long long lj=0;
	for(int i=1;i<=m;i++)
	{
		long long fu=ff(edge[i].u),fv=ff(edge[i].v);
		if(fu==fv) continue;
		fa[fu]=fv;
		ans+=edge[i].w;
		lj++;
		if(lj==n-1) break;
	}
	printf("%lld",ans);
	return;
}
void solve2()
{
	ans=1e18;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	bool flag=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i]!=0) flag=0;
		for(long long j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	if(flag)
	{
		solve3();
		return;
	}
	qdgs=n;
	act_dfs(1);
	printf("%lld",ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==0)
	{
		solve1();
		return 0;
	}
	else
	{
		solve2();
		return 0;
	}
}
