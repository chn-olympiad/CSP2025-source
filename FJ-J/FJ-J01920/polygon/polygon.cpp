#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXX = 50005;
long long n, a[505], sum[MAXX], f[505], maxx, ans;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	sum[0] = 1;
	for (int i = 1;i <= n;i++)
	{
		for (int j = a[i] + 1;j <= maxx;j++)
			f[i] = (sum[j] + f[i]) % MOD;
		for (int j = maxx;j >= 0;j--)
		{
			if (sum[j])
				sum[j + a[i]] = (sum[j] + sum[j + a[i]]) % MOD;
		}
		maxx += a[i];
		f[0] = f[1] = f[2] = 0;
		ans = (ans + f[i]) % MOD;
	}
	cout << ans;
	return 0;
}
