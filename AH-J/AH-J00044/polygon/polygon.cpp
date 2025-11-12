#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
const long long MOD = 998244353;
int a[N], p, ans, dp2[N];
int Qpow(int b, int a = 2)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
			res = 1LL * res * a % MOD;
		a = 1LL * a * a % MOD;
		b >>= 1;
	}
	return res;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), p = max(a[i], p);
	sort(a + 1, a + n + 1);
	dp2[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= a[i]; ++j)
			(ans += dp2[j]) %= MOD;
		for (int j = p - a[i]; j >= 0; --j)
			(dp2[j + a[i]] += dp2[j]) %= MOD;
	}
	cout << ((Qpow(n) - ans - 1) % MOD + MOD) % MOD;
	return 0;
}

