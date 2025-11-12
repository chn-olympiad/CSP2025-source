#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,tag,tot,sum,cnt;
ll fa[20005],c[25],a[20005],pre[20005];
struct Edge
{
	ll pre,to,w;
}e[4000005];
bool cmp(Edge &a,Edge &b)
{
	return a.w<b.w;
}
void add(ll &x,ll &y,ll &z)
{
	e[++tot].pre=x;
	e[tot].to=y;
	e[tot].w=z;
	pre[x]=tot;
	return;
}
ll find(ll &x)
{
	return x==fa[x]?x:find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%d%d",&n,&m,&k);
	for(ll i=1;i<=n;i++)fa[i]=i;
	for(ll i=1;i<=m;i++)
	{
		ll x,y,z;
		scanf("%lld%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(ll i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++)
		{
			scanf("%lld",&a[j]);
			if(a[j]==0)tag=j;
		}
		for(ll j=1;j<=n;j++)
		{
			if(j!=tag)
			{
				add(tag,j,a[j]);
			}
		}
	}
	sort(e+1,e+tot+1,cmp);
	for(ll i=1;i<=tot&&cnt<n-1;i++)
	{
		ll x=find(e[i].pre),y=find(e[i].to);
		if(x==y)continue;
		else
		{
			fa[x]=y;
			sum+=e[i].w;
			cnt++;
		}
	}
	printf("%lld",sum);
	return 0;
}
