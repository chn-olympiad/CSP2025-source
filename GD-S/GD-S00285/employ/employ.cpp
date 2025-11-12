#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
#define csep constexpr
#define empb emplace_back
csep i32 inf32 = 0x3f3f3f3f;
csep i64 inf64 = 0x3f3f3f3f3f3f3f3fll;

// ---------------------------------------------------------------

csep i32 mod = 998244353;

i32 n, l, dp[20][1000000], c[20];
bool ps[20];

inline i32 dig(i32 S, i32 x) {return ((S >> x) & 1);}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> l;
	for (i32 i = 1; i <= n; ++i) {
		char t;
		cin >> t;
		ps[i] = t - '0';
	}
	for (i32 i = 0; i < n; ++i)
		cin >> c[i];
	dp[0][0] = 1;
	for (i32 i = 0; i <= n; ++i) {
		for (i32 S = 0; S < (1 << n); ++S) {
			if (__builtin_popcount(S) < i)
				continue;
			i32 unp = __builtin_popcount(S) - i;
			for (i32 j = 0; j < n; ++j) {
				if (!dig(S, j))
					continue;
				// passed
				if (i && ps[__builtin_popcount(S)] && c[j] > unp)
					(dp[i][S] += dp[i - 1][S ^ (1 << j)]) %= mod;
				// didn't pass, or gave up
				if (!ps[__builtin_popcount(S)] || c[j] <= unp - 1)
					(dp[i][S] += dp[i][S ^ (1 << j)]) %= mod;
			}
		}
	}
	i32 ans = 0;
	for (i32 i = l; i <= n; ++i)
		(ans += dp[i][(1 << n) - 1]) %= mod;
	cout << ans << endl;
	fflush(stdout);
	return 0;
}