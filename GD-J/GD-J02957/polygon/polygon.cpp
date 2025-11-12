#include <iostream>
using namespace std;

using ll = long long;

const int N = 5005, MOD = 998244353;

ll n, a[N], dp[N][N], ans = 0;

inline void dfs(ll cur, ll maxa, ll p)
{
	if (cur > (maxa << 1))
	{
		++ ans;
		ans = ans % MOD;
	}
	
	for (int i = p + 1; i <= n; ++ i)
	{
		dfs(cur + a[i], max(maxa, a[i]), i);
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	scanf("%lld", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%lld", &a[i]);
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; ++ i)
	{
		cnt += (a[i] == 1);
	}
	
	if (cnt == n)
	{
		printf("%lld\n", (n * (n - 1LL) * (n - 2LL) / 6LL) % MOD);
		return 0;
	}
	
	dfs(0, 0, 0);
	
	printf("%lld\n", ans % MOD);
	return 0;
}
