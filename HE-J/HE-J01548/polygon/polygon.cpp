#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=5005;
ll a[MAXN];
ll n,ans;
bool solve(ll l,ll r)
{
	ll cnt=0,o=l,maxc=0;
	while(o<r)
	{
		cnt+=a[o];
		maxc=max(maxc,a[o]); 
		o++;
	}
	if(cnt>maxc*2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll l=0;l<n-3;l++)
	{
		for(ll r=l;r<n;r++)
		{
			if(solve(l,r)==true)
			{
				ans++;
			}
		}
	}
	if(ans>998)
	{
		cout<<ans%998;
	}
	else if(ans>353)
	{
		cout<<ans%353;
	}
	else if(ans>244)
	{
		cout<<ans%244;
	}
	else
	{
		cout<<ans;
	}
	return 0;
}
