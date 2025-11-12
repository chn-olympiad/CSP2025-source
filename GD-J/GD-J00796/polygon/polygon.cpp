#include<bits/stdc++.h>
#define ll long long
#define mid 998244353
using namespace std;
ll nb(ll x,ll y)
{
	ll fg=x;
	for(ll i=x-1;i>x-y;i--)
	{
		(fg*=i)%mid;
	}
	for(ll i=1;i<=y;i++)
	{
		fg/=i;
	}
	return fg;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,ans=0;
	cin>>n;
	for(ll i=3;i<=n;i++)
	{
		(ans+=nb(n,i))%998244353;
		
	}
	cout<<ans%998244353;
}
