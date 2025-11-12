#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int mod = 998244353;

struct modint {
	int val;
	modint() { val = 0; };
	template<typename T>
	modint(T v) {
		val = (v % mod + mod) % mod;
	}
	friend modint operator+(modint a, modint b) {
		modint res;
		res.val = a.val + b.val;
		if (res.val >= mod) {
			res.val -= mod;
		}
		return res;
	}
	friend modint operator-(modint a, modint b) {
		modint res;
		res.val = a.val - b.val;
		if (res.val < 0) {
			res.val += mod;
		}
		return res;
	}
	friend modint operator*(modint a, modint b) {
		modint res;
		res.val = 1ll * a.val * b.val % mod;
		return res;
	}
	void operator+=(modint a) {
		*this = *this + a;
	}
	void operator-=(modint a) {
		*this = *this - a;
	}
	void operator*=(modint a) {
		*this = *this * a;
	}
	friend modint pow(modint a, i64 b) {
		modint res = 1;
		while (b) {
			if (b & 1) {
				res *= a;
			}
			b >>= 1;
			a *= a;
		}
		return res;
	}
	modint inv() {
		return pow(*this, mod - 2);
	}
};

#define sr cin
#define sw cout
#define sendl '\n'
#define mika cout.flush();return 0

int a[5010];
modint dp[5010][5010], s[5010][5010], ans;

int main() {
	ios::sync_with_stdio(false);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	sr >> n;
	for (int i = 1; i <= n; i++) {
		sr >> a[i];
	}
	sort(a + 1, a + n + 1);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i]; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		for (int j = 0; j <= 5000 - a[i]; j++) {
			dp[i][j + a[i]] = dp[i - 1][j + a[i]] + dp[i - 1][j];
		}
	}
	for (int i = 0; i <= n; i++) {
		s[i][0] = dp[i][0];
		for (int j = 1; j <= 5000; j++) {
			s[i][j] = s[i][j - 1] + dp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		modint g = s[i - 1][a[i]];
		modint r = pow(modint(2), i - 1);
		ans += r - g;
		// sw << pow(modint(2), i - 1).val << " " << g.val << sendl;
	}
	sw << ans.val << sendl;
	mika;
}