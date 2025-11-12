#include <bits/stdc++.h>

using namespace std;

const long long N = 5005, mod = 998244353;

long long n, a[N], k, cnt;

void dfs(long long d, long long s, long long maxn)
{
	if (d == n + 1ll)
	{
		if (s > maxn * 2ll) cnt = (cnt + 1ll) % mod ;
		return;
	}
	dfs(d + 1ll, s + a[d], max(maxn, a[d]));
	dfs(d + 1ll, s, maxn);
}

long long ksm(int a, int b)
{
	long long ans = 1ll;
	while (b)
	{
		if (b & 1ll) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1ll;
	}
	return ans;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%lld", &a[i]);
	}
	if (n <= 20ll)
	{
		dfs(1ll, 0ll, 0ll);
		cout << cnt << endl;
	}
	else
	{
		cout << (ksm(2ll, n) - (1ll + n + n * (n - 1ll)) % mod + mod) % mod << endl;
	}
	return 0;
}


