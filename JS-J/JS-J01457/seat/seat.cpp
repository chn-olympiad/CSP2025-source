#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll students[105];
bool f(ll a,ll b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i <= n*m;i++)
	{
		cin>>students[i];
	}
	ll me=students[1];
	sort(students+1,students+1+n*m,f);
	ll ans,bns;
	for(ll i = 1;i <= n*m;i++)
	{
		if(students[i]==me)
		{
			ans=i;
		}
	}
	double cns=(double)ans/n;
	ll dns=ans/n;
	if(cns!=dns)
	{
		dns++;
	}
	if(dns%2)
	{
		bns=ans%n;
		if(bns==0)
		{
			bns=n;
		}
	}
	else
	{
		ll ens=ans%n;
		if(ens==0)
		{
			ens=n;
		}
		bns=n+1-ens;
	}
	cout<<dns<<' '<<bns<<"\n";
	return 0;
}