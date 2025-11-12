#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll t,n,ans,ha,hb,hc,fc[N],f[N],fcc[N],h;
struct T{ ll a,b,c;}a[N];
ll mx(ll x,ll y){ return (x > y ? x : y);}
ll mn(ll x,ll y){ return (x < y ? x : y);}
void mian()
{
	ans=ha=hb=hc=h=0;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
	for(ll i=1;i<=n;i++)
	{
		if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
		{
			fc[i]=a[i].a-max(a[i].b,a[i].c);
			ans+=a[i].a,f[i]=1,ha++;
		}
		else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
		{
			fc[i]=a[i].b-max(a[i].a,a[i].c);
			ans+=a[i].b,f[i]=2,hb++;
		}
		else
		{
			fc[i]=a[i].c-max(a[i].b,a[i].a);
			ans+=a[i].c,f[i]=3,hc++;
		}
	}
	if(ha>n/2)
	{
		for(ll i=1;i<=n;i++)
		{
			if(f[i]==1) fcc[++h]=fc[i];
		}
		sort(fcc+1,fcc+h+1);
		for(ll i=1;i<=ha-n/2;i++) ans-=fcc[i];
	}
	else if(hb>n/2)
	{
		for(ll i=1;i<=n;i++)
		{
			if(f[i]==2) fcc[++h]=fc[i];
		}
		sort(fcc+1,fcc+h+1);
		for(ll i=1;i<=hb-n/2;i++) ans-=fcc[i];
	}
	else if(hc>n/2)
	{
		for(ll i=1;i<=n;i++)
		{
			if(f[i]==3) fcc[++h]=fc[i];
		}
		sort(fcc+1,fcc+h+1);
		for(ll i=1;i<=hc-n/2;i++) ans-=fcc[i];
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) mian();
	return 0;
}
