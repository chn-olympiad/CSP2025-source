#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	unsigned long long ans=0,t;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n==3)
	{
		if (a[1]+a[2]>a[3])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		for (int i=2;i<n;++i)
		{
			t=i;
			for (int j=2;j<=i;++j)
			{
				t=t*(i-j+1)/j;
				ans=(ans+t)%mod;
			}
		}
		cout<<ans;
	}
	return 0;
}
