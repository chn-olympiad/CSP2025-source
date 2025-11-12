#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],ch[5005];
long long int ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		sum[i] = sum[i-1] + a[i];
		ch[i] = a[i] - a[i-1];
	}
	/*for(int i = 4;i <= n;i++)
	{
		for(int j = 0;j <= n-3;j++)
		{
			if(sum[i] - sum[j] > 2 * a[i])
			{
				ans++;
			}
		}
	}*/
	for(int i = 1;i <=n-2;i++)
	{
		for(int j = i+1;j <= n-1;j++)
		{
			for(int k = j+1;k <= n;k++)
			{
				if(a[i] + a[j] + a[k] > 2*a[k])
				{
					ans++;
				}
			}
		}
	}
	/*for(int i = n;i >= 1;i--)
	{
		
	}*/
	cout << ans % 998244353;
	return 0;
}
