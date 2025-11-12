#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005];
long long MOD = 998244353,cnt = 0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	if (n == 3)
	{
		int sum = 0,maxx = 0;
		for (int i = 1;i <= 3;i++)
		{
			sum += a[i];
			maxx = max(maxx,a[i]);
		}
		if (sum > maxx*2)
			cout << 1;
		else
			cout << 0;
			return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		sum[i] = sum[i-1]+a[i];
	}
	long long maxx = 0;
	for (int i = 1;i <= n-2;i++)
	{
		for (int j = i;j <= i+2;j++)
			maxx = max(maxx,(long long)a[j]);
		for (int j = i+2;j <= n;j++)
		{
			maxx = max(maxx,(long long)a[j]);
			if ((sum[j] - sum[i-1]) > maxx*2)
				cnt++;
			cnt %= MOD;
		}
	}
	cout << cnt % MOD;
	return 0;
}
