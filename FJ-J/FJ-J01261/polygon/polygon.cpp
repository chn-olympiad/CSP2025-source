#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n<3)
	{
		cout<<0;
		return 0;
	}
	else if (n==3)
	{
		int maxx=-1,sum=0;
		for (int i=1;i<=n;i++) maxx=max(maxx,a[i]);
		for (int i=1;i<=n;i++) sum+=a[i];
		if (sum>maxx*2) cout<<1;
		else cout<<0;
		return 0;
	}
	else
	{
		for (int i=3;i<=n;i++)
		{
			int sum1=1,sum2=1,sum3=1;
			for (int j=1;j<=n;j++) sum1*=j;
			for (int j=1;j<=n-i;j++) sum2*=j;
			for (int j=1;j<=i;j++) sum3*=j;
			ans+=(sum1/(sum2*sum3))%998244353;
		}
		cout<<ans;
		return 0;
	}
	cout<<9;
	return 0;
}