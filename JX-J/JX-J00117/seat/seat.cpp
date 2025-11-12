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

struct node {
	int id, v;
} a[110];

bool cmp(node a, node b) {
	return a.v > b.v;
}

int main() {
	ios::sync_with_stdio(false);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	sr >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		sr >> a[i].v;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int d = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1) {
			d = i;
			break;
		}
	}
	int x = 1, y = 1;
	while (--d) {
		if (x % 2 == 1) {
			y++;
		} else {
			y--;
		}
		if (y == 0) {
			y = 1;
			x++;
		}
		if (y == n + 1) {
			y = n;
			x++;
		}
	}
	sw << x << " " << y << sendl;
	mika;
}