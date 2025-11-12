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

int main() {
	ios::sync_with_stdio(false);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string str;
	sr >> str;
	vector<int> ans;
	for (char i : str) {
		if ('0' <= i && i <= '9') {
			ans.push_back(i - '0');
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	for (int i : ans) {
		sw << i;
	}
	sw << sendl;
	mika;
}