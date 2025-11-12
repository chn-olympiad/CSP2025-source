#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int sum[5005],a[5005];
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	long long ans=0;
	for(int i=1;i<=n-2;i++)
	{
		int ch2=n-i-1;
		long long ch1=i+2;
		if(ch1>=4)
		{
			long long t=1;
			for(int j=4;j<=ch1;j++)
			{
				t*=j;
				t=t%mod;
			}
			ch1=t;
		}
		ans=ans+(ch1*ch2)%mod;
		ans%=mod;
	}
	cout << ans;
	return 0;
}