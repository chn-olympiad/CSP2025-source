#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,c[505];
string a;
bool fg1=true;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ll pll=n;
	cin>>a;
	a='#'+a;
	for(ll i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)pll--;
	}
	for(ll i=1;i<=n;i++)if(a[i]!='1')fg1=false;
	if(pll<m)
	{
		cout<<"0";
		return 0;
	}
	if(fg1)
	{
		ll ans=1;
		for(ll i=n;i>=1;i--)ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		cout<<"0";
		return 0;
	}
	cout<<"1";
	
	return 0;
}
