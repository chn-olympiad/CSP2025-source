#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	long long ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int tallest_2 = 0;
	for (int i = 0;i < n;i++)
	{
		tallest_2 += pow(2,i);
	}
	for (int i = 7;i <= tallest_2;i++)
	{
		const long long N = pow(2,4999) + 5;
		int erjinzhishu[N];
		int nn = i;
		for (int j = n;j >= 1;j--)
		{
			if (nn >= pow(2,j - 1))
			{
				erjinzhishu[j] = 1;
				nn -= pow(2,j - 1);
			}
			else if (nn < pow(2,j - 1))
			{
				erjinzhishu[j] = 0;
			}
		}
		int shiyong[5005],si = 0;
		for (int j = 1;j <= n;j++)
		{
			shiyong[j] = 0;
		}
		for (int j = n;j >= 1;j--)
		{
			if (erjinzhishu[j] == 1)
			{
				si += 1;
				shiyong[si] = a[n - j + 1];
			}
		}
		if (si >= 3)
		{
			int maxs = 0,sum = 0;
			for (int j = 1;j <= n;j++)
			{
				sum += shiyong[j];
				if (shiyong[j] > maxs)
				{
					maxs = shiyong[j];
				}
			}
			if (sum > maxs * 2)
			{
				ans += 1;
			}
		}
	}
	cout << ans % 998244353;
	return 0;
}