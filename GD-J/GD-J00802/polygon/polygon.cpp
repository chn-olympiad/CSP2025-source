#include <bits/stdc++.h> 
using namespace std;
const int MOD = 998244353;
int n, a[5005];
long long ans;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (n > 30)
	{
		long long sum = 1, sum2 = 1;
		for (int i = 1; i <= n; i++)
		{
			sum *= i;
			sum %= MOD;
			if (i > n-2)
			{
				continue;
			}
			sum2 *= i;
			sum2 %= MOD;
		}
		cout << sum-sum2-n;
		return 0;
	}
	for (long long i = 1; i < (1 << n); i++)
	{
		long long sum = 0, num = 0;
		int x = -1;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				sum += a[j+1];
				num++;
				x = max(x, a[j+1]);
			}
		}
		if (num < 3)
		{
			continue;
		}
		if (sum > 2*x)
		{
			ans++;
		}
		else
		{
			continue;
		}
		ans %= MOD;
	}
	cout << ans % MOD;
	return 0;
}
