#include<bits/stdc++.h>
using namespace std;
struct ROAD
{
	long long u,v,w;
}r[1505000];
bool cmp(ROAD a,ROAD b)
{
	return a.w<b.w;
}
long long n,m,k,cnt,fa[1505000],c[15],u[15],CNT,ans;
long long gf(long long v)
{
	if(v==fa[v])return v;
	long long GF=gf(fa[v]);
	fa[v]=GF;
	return GF;
}
void ADD(long long B)
{
	long long gfa=gf(r[B].u),gfb=gf(r[B].v);
	if(gfa==gfb)return;
	fa[gfa]=gfb;
	ans+=r[B].w;
	CNT++;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	for(long long i=1;i<=m;i++)
	{
		cnt++;
		scanf("%lld%lld%lld",&r[cnt].u,&r[cnt].v,&r[cnt].w);
	}
	for(long long i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(long long j=1;j<=n;j++)
		{
			cnt++;
			r[cnt].u=n+i;
			r[cnt].v=j;
			scanf("%lld",&r[cnt].w);
			if(r[cnt].w==0)
			{
				ADD(cnt);
			}
		}
	}
	sort(r+1,r+cnt+1,cmp);
	for(long long i=1;i<=cnt&&CNT<n+k;i++)
	{
//		cout<<CNT<<endl;
		ADD(i);
	}
	printf("%lld",ans);
	return 0;
}
