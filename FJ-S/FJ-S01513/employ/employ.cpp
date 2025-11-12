#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5e2 + 5;
const int MOD = 998244353;

int n, m;
int fac[MAXN], c[MAXN];
char s[MAXN];

namespace Subtask12 {
	int dp[15][15][1 << 12];
	
	int pop_count(int x) {
		int ret = 0;
		while (x) {
			if (x & 1)
				++ret;
			x >>= 1;
		}
		return ret;
	}
	
	int ans = 0;
	
	int dfs(int i, int j, int sta) {
		if (i > n)
			return j <= n - m;
		int ret = 0;
		for (int x = 1; x <= n; ++x) {
			if ((sta & (1 << (x - 1))))
				continue;
			if (s[i] == '1' && j < c[x])
				ret = (1ll * ret + dfs(i + 1, j, sta | (1 << (x - 1)))) % MOD;
			else
				ret = (1ll * ret + dfs(i + 1, j + 1, sta | (1 << (x - 1)))) % MOD;
		}
		return ret;
	}
	
	void solve(void) {
		int maxsta = 1 << n;
		for (int x = 1; x <= n; ++ x) {
			if (c[x] && s[1] == '1')
				dp[1][0][1 << (x - 1)] = 1;
			else if (s[1] == '0')
				dp[1][1][1 << (x - 1)] = 1;
		}
		for (int i = 2; i <= n; ++i) {
			for (int sta = 0; sta < maxsta; ++sta) {
				if (i != pop_count(sta))
					continue;
				for (int x = 1; x <= n; ++x) {
					if (!(sta & (1 << (x - 1))))
						continue;
					if (s[i] == '1') {
						dp[i][0][sta] = (1ll * dp[i][0][sta] + dp[i - 1][0][sta ^ (1 << (x - 1))]) % MOD;
						for (int j = 0; j <= i; ++j) {
							if (j >= c[x])
								dp[i][j + 1][sta] = (1ll * dp[i][j + 1][sta] + dp[i - 1][j][sta ^ (1 << (x - 1))]) % MOD;
							else
								dp[i][j][sta] = (1ll * dp[i][j][sta] + dp[i - 1][j][sta ^ (1 << (x - 1))]) % MOD;
						}
					} else if (s[i] == '0') {
						for (int j = 1; j <= i; ++j) {
							dp[i][j][sta] = (1ll * dp[i][j][sta] + dp[i - 1][j - 1][sta ^ (1 << (x - 1))]) % MOD;
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = n - m; i >= 0; --i)
			ans = (1ll * ans + dp[n][i][maxsta - 1]) % MOD;
		printf("%d\n", ans);
	}
}

namespace SubtaskA {
	void solve(void) {
		printf("%d\n", fac[n]);
	}
}

int main(void) {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	fac[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		fac[i] = 1ll * fac[i - 1] * i % MOD;
	scanf("%d %d", &n, &m);
	bool flagA = true;
	scanf("%s", (s + 1));
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0')
			flagA = false;
	}
	for (int i = 1; i <= n; ++i)
		scanf("%d", c + i);
	if (n <= 10) {
		printf("%d\n", Subtask12::dfs(1, 0, 0));
		return 0;
	}
	if (flagA) {
		SubtaskA::solve();
		return 0;
	}
	return 0;
}
