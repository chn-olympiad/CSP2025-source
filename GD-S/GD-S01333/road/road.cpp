#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	ll u,v,w;
};
node a[1100001];
ll father[10001];
ll get(ll x)
{
	if (father[x]==x)
	{
		return x;
	}
	return father[x]=get(father[x]);
}
void merge(ll x,ll y)
{
	x=get(x);
	y=get(y);
	father[x]=y;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k,x,y,z,cnt,sum=0,ans=0;
	scanf("%lld%lld%lld",&n,&m,&k);
	for (ll i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	cnt=m;
	for (ll i=1;i<=k;i++)
	{
		scanf("%lld",&x);
		for (ll j=1;j<=n;j++)
		{
			scanf("%lld",&x);
			cnt++;
			a[cnt]=(node){i+n,j,x};
		}
	}
	for (ll i=1;i<=n+k;i++)
	{
		father[i]=i;
	}
	sort(a+1,a+cnt+1,cmp);
	for (ll i=1;i<=cnt;i++)
	{
		x=a[i].u;
		y=a[i].v;
		z=a[i].w;
		if (get(x)==get(y))
		{
			continue;
		}
		merge(x,y);
		ans+=z;
		sum++;
		if (sum==n+k-1)
		{
			printf("%lld",ans);
			return 0;
		}
	}
	return 0;
}
