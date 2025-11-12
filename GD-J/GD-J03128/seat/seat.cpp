#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,rk;
pair<ll,ll> a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+1+n*m);
	for(ll i=1;i<=n*m;i++)
	{
		if(a[i].second==1)
		{
			rk=n*m-i;
			break;
		}
	}
	ll x=1,y=1,f=1;
	for(ll i=1;i<=rk;i++)
	{
		if(x==n&&f==1)y++,f=-1;
		else if(x==1&&f==-1)y++,f=1;
		else x+=f;
	}
	printf("%lld %lld\n",y,x);
	
	return 0;
}
