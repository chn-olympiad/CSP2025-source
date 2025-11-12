#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

#define PROBLEM_NAME "employ"
#define MULTIPLE_TEST 0

struct Solver {
	static constexpr int mod = 998244353;
	struct In {
		int n, m;
		int s[510];
		int c[510];
		In() {
			char ch;
			std::cin >> n >> m;
			for (int i = 1; i <= n; i++)
				std::cin >> ch, s[i] = ch ^ 48;
			for (int i = 1; i <= n; i++)
				std::cin >> c[i];
		}
	} in;
	struct Out {
		int ans;
		~Out() { std::cout << ans << '\n'; }
	} out;
	int dp[262160][30][30];
	int ppcnt[262160];
	Solver() {}
#define ADD(x, y) (x = (x + (y)) % mod)
	inline void Work() {
		dp[0][0][0] = 1;
		for (int i = 1; i < 1 << in.n; i++)
			ppcnt[i] = ppcnt[i & (i - 1)] + 1;
		for (int i = 0; i < 1 << in.n; i++) {
			for (int t = 1; t <= in.n; t++) {
				if (i & (1 << (t - 1))) continue;
				for (int j = 0; j <= in.n; j++) {
					for (int k = 0; k < in.n; k++) {
						if (in.s[ppcnt[i] + 1] && j < in.c[t]) {
							ADD(dp[i | (1 << (t - 1))][0][k + 1], dp[i][j][k]);
						} else {
							ADD(dp[i | (1 << (t - 1))][j + 1][k], dp[i][j][k]);
						}
					}
				}
			}
		}
		for (int i = 0; i <= in.n; i++)
			for (int j = in.m; j <= in.n; j++)
				ADD(out.ans, dp[(1 << in.n) - 1][i][j]);
	}
#undef ADD
};

int main() {
	static uint8_t space[sizeof(Solver)];
	freopen(PROBLEM_NAME ".in", "r", stdin);
	freopen(PROBLEM_NAME ".out", "w", stdout);
	// Overriding stdin/stdout, evil but working...
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	int T;
#if MULTIPLE_TEST == 1
	std::cin >> T;
#else
	T = 1;
#endif
	while (T--) {
		Solver *solver = new (space) Solver();
	       	solver -> Work();
		solver -> ~Solver();
		if (T) memset(space, 0, sizeof(space));
	}
	return 0;
}
#undef PROBLEM_NAME
#undef MULTIPLE_TEST