#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010],sum=0,mx=INT_MIN,ans=0;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(n==3)
	{
		if(sum<=(mx*2))
		{
			cout<<0;
			return 0;
		}
		else
		{
			cout<<1;
			return 0;
		}
	}
	for(int i=3;i<=n;i++)
	{
		ans+=(n-i+1);
	}
	cout<<ans%998244353;
	return 0;
}
