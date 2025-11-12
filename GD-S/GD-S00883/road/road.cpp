#include<bits/stdc++.h>
using namespace std;
const long long N=2000009;
long long n,m,k,fa[N],c[N];
struct node{long long u,v,w;}a[N];
bool cmp(node x,node y){return x.w<y.w;}
long long getfa(long long x)
{
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++)
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	for(long long i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(long long j=1;j<=n;j++)
		{
			a[++m].u=i+n,a[m].v=j;
			scanf("%lld",&a[m].w);
		}
	}
	sort(a+1,a+m+1,cmp);
	long long anss=9147483647000000000;
	for(long long S=0;S<(1<<k);S++)
	{
		for(long long i=1;i<=n+k;i++) fa[i]=i;
		long long ans=0,cnt=n-1;
		for(long long j=1;j<=k;j++)
			if(S&(1<<(j-1))) cnt++,ans+=c[j];
		for(long long j=1;j<=m;j++)
		{
			long long U=getfa(a[j].u);
			long long V=getfa(a[j].v);
			if(U==V) continue;
			if(a[j].u>n&&!(S&(1<<(a[j].u-n-1))))
				continue;
			ans+=a[j].w; fa[U]=V;
			cnt--; if(cnt<=0) break;
		}
		anss=min(anss,ans);
	}
	printf("%lld",anss);
	return 0;
}
