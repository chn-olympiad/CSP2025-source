#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 5, MOD = 998244353;

ll n, a[MAXN], dp[MAXN][MAXN], pre[MAXN];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i]; pre[i] = pre[i - 1] + a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 2 * a[i] + 1; j <= pre[i]; j ++)
		{
			dp[i][j] = (dp[i][j] + (((dp[i - 1][j - a[i]] % MOD) + 1) % MOD)) % MOD;
		}
	}
	
	ll ans = 0;
	
	for (int i = 1; i <= n; i ++) for (int j = 0; j <= pre[i]; j ++) ans = (ans + dp[i][j]) % MOD;
	
	cout << (ans + MOD) % MOD;
	
	return 0;
}
