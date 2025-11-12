#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll lowbits(ll x)
{
	return x&(-x);
}
ll ct(ll x)
{
	ll cnt=0;
	while(x)
	{
		x^=(x&(-x)),cnt+=1;
	}
	return cnt;
}
ll n,mxn=0,mx,sumk,ans=0;
vector<ll> ve;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=0,v;i<n;i++)
	{
		cin>>v;
		ve.push_back(v),mxn=(mxn<<1)|1;
	}
	for(ll i=0,k,t;i<=mxn;i++)
	{
		if(ct(i)<3)
		{
			continue;
		}
		k=i,t=-1,sumk=0,mx=0;
		while(k)
		{
			t+=1;
			if((((ll)(k&1))==1))
			{
				sumk+=ve[t],mx=ve[t]>mx?ve[t]:mx;
			}
			k=k>>1;
		}
		if((mx<<1)<sumk)
		{
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}