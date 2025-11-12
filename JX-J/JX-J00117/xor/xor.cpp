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
	modint operator+=(modint a) {
		return *this + a;
	}
	modint operator-=(modint a) {
		return *this - a;
	}
	modint operator*=(modint a) {
		return *this * a;
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

int dp[500010];
unordered_map<int, int> mp;

int main() {
	ios::sync_with_stdio(false);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	sr >> n >> k;
	mp[0] = 0;
	int now = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		sr >> x;
		now ^= x;
		if (mp.count(now ^ k)) {
			dp[i] = dp[mp[now ^ k]] + 1;
		}
		mp[now] = i;
		dp[i] = max(dp[i], dp[i - 1]);
	}
	sw << dp[n] << sendl;
	mika;
}