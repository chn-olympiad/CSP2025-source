#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k;
ll a[501000],vis[501000];
ll cnt=0;
bool sk(ll l,ll r)
{
	for(ll i=l;i<=r;i++)
	{
		if(vis[i]==1)return false;
	}
	return true;
}
bool f(ll l,ll r)
{
	ll num=a[l];
	for(ll i=l+1;i<=r;i++)num=num^a[i];
	if(num==k&&sk(l,r)==true)
	{
		for(ll i=l;i<=r;i++)vis[i]=1;
		return true;	
	}
	return false;
}
int main()
{
 	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
 	cin>>n>>k;
 	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++)
		for(ll j=i;j<=n;j++)
			if(f(i,j))cnt++;
	cout<<cnt;
   	return 0;
}
