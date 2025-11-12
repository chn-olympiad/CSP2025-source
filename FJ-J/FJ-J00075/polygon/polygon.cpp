#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll Mod=998244353;
ll a[5010],s[5010];
ll ans=0,n;
void solve1()
{
	ll x=0;
	for (int i=1;i<=n-2;i++)
	x+=i,x%=Mod,s[i]=(s[i-1]+x)%Mod;
	for (int i=1;i<=n-2;i++)
	ans+=s[i];
}
void solve2()
{
	if (a[1]+a[2]>a[3]) ans=1;
}
int main()
{ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if (n<=3) solve2();
	else if (a[n]==1) solve1();
	else
	{
		for (int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
		for (int i=3;i<=n;i++)
		if (s[i-1]<=a[i]) continue;
		else ans++;
	}	
	cout<<ans;
	return 0;
}

