#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,uu,vv,ll;
int a[1005][1005];
int c[7];
struct edge
{
	int u,v,l;
}e[1000005];
int fa[10005];
int li[7][1005];
bool cmp(edge a,edge b)
{
	return a.l<b.l;
}
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
int kru()
{
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+cnt+1,cmp);
	int gs=0,ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int s=find(e[i].u),t=find(e[i].v);
		if(s!=t)
		{
			fa[s]=t;
			gs++,ans+=e[i].l;
			if(gs>=n-1)return ans;
		}
	}
	return 0x3f3f3f3f3f3f3f3f;
}
void lian(int i)
{
	for(int j=1;j<n;j++)
		for(int kk=j+1;kk<=n;kk++)
			a[j][kk]=min(a[j][kk],li[i][j]+li[i][kk]);
}
void zh()
{
	cnt=0;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i][j]!=0x3f3f3f3f3f3f3f3f)
				e[++cnt]={i,j,a[i][j]};
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==0)
	{
		for(int i=1;i<=m;i++)
			scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].l);
		printf("%lld",kru());
		return 0;
	}
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&uu,&vv,&ll);
		a[vv][uu]=a[uu][vv]=min(a[uu][vv],ll);
	}
	bool f=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i])f=0;
		for(int j=1;j<=n;j++)
			scanf("%lld",&li[i][j]);
	}
	if(f)
	{
		for(int i=1;i<=k;i++)lian(i);
		zh();
		printf("%lld",kru());
		return 0;
	}
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<1<<k;i++)
	{
		int cc=0,tt=i,res=0;
		while(tt)
		{
			cc++;res+=c[cc];
			if(tt&1)lian(cc);
			tt>>=1;
		}
		zh();
		ans=min(ans,res+kru());
	}
	printf("%lld",ans);
	return 0;
}
