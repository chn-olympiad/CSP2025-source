#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int n;
long long ans;
int a[5005],d[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		d[i] = d[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	if (a[n] == 1) 
	{
		for (int i = 2;i <= n-3;i ++)
		{
			int tmp = 1
			for (int j = n;j >= n-i+1;j --)
			{
				tmp = (tmp*j)%mod;
			}
			for (int k = 2;k <= i;k ++)
			{
				tmp = (tmp/k)%mod;
			}
			ans = (ans+tmp)%mod;
		}
		cout << (ans+n+1)%mod;
		return 0;
	}
	for (int i = 3;i <= n;i ++)
	{
		for (int j = 1;j < i-1;j ++)
		{
			int x = d[i] - d[j-1];
			if (x > 2*a[i])
			{
				ans = (ans+1)%mod;
			}
			for (int k = j+1;k < i;k ++)
			{
				for (int p = j+1;p <= k;p ++)
				{
					if (x - (d[k]-d[p-1]) > 2*a[i])
					{
						ans = (ans+1)%mod;
					}		
				}
			}
		}
	}
	cout << ans%mod;
	return 0;
}

