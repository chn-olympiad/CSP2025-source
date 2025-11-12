#include <stdio.h>
#include <iostream>

constexpr int MOD = 998244353;
constexpr int N = 505;
int c[N];
int popcnt[(1 << 18) + 5];
int dp[(1 << 18) + 5][18 + 1];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

//	freopen("employ3.in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	int m;
	std::cin >> m;
	std::string str;
	std::cin >> str;
	for (int i = 1; i <= n; ++i)
		std::cin >> c[i];
	if (n <= 18) {
		dp[0][0] = 1;
		for (int s = 1; s <= (1 << n) - 1; ++s)
			popcnt[s] = popcnt[s ^ (s&-s)] + 1;
		for (int s = 0; s <= (1 << n) - 2; ++s) {
			for (int i = 1; i <= n; ++i) {
				if (s & (1 << (i - 1)))
					continue;
				const int t = s | (1 << (i - 1));
				if (str[popcnt[s]] == '0') {
					for (int j = 0; j <= popcnt[s]; ++j)
						dp[t][j + 1] = (dp[t][j + 1] + dp[s][j]) % MOD;
				} else {
					for (int j = 0; j < c[i]; ++j)
						dp[t][j] = (dp[t][j] + dp[s][j]) % MOD;
					for (int j = c[i]; j <= popcnt[s]; ++j)
						dp[t][j + 1] = (dp[t][j + 1] + dp[s][j]) % MOD;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= n - m; ++i)
			ans = (ans + dp[(1 << n) - 1][i]) % MOD;
		std::cout << ans;
	} else {
		int ans = 1;
		for (int i = 1; i <= n; ++i)
			ans = (long long)ans * i % MOD;
		std::cout << ans;
	}
	return 0;
}

