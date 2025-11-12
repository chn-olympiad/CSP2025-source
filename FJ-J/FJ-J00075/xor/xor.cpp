#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500020],ans=0,k,n;
map<ll,ll> mp;
void solve1()
{
	if (n==2 && k==0) ans=1;
	if (n==1 && k==0) ans=0;
}
void solve2()
{
	ans=n/2;
}
void solve3()
{
	ll s=1;
	if (k==1) ans=mp[1];
	else
	for (int i=2;i<=n;i++)
	{
		if (a[i]==a[i-1] && a[i]==1) s++;
		else
		ans+=s/2,s=1;
	}
	ans=max(ans,mp[0]);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	if (n<=2) solve1();
	else if (mp[1]==n) solve2();
	else if (mp[1]+mp[0]==n) solve3();
	cout<<ans;
	return 0;
}

