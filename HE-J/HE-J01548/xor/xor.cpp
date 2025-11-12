#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans;
const ll MAXN=500005;
ll x[MAXN];
ll solve(ll l,ll r)
{
	ll q=l;
	for(ll p=l+1;p<=r;p++)
	{
		if(x[p]==-1)
		{
			return -1;
		}
		q^=x[p];
	}
	return q;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(ll l=0;l<n;l++)
	{
		bool flag=false;
		for(ll r=l;r<n;r++)
		{
			if(solve(l,r)==k)
			{
				flag=true;
				for(int i=l;i<=r;i++)
				{
					x[i]=-1;
				} 
				break;
			}
		}
		if(flag==true)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
