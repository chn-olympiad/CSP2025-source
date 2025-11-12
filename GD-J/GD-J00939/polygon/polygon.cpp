#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dwn(i, j, k) for(int i = (j); i >= (k); --i)
#define int long long
#define ull unsigned long long
#define endl '\n'

using namespace std;

constexpr int N = 1e5 + 7, mod = 998244353;

int f[N], a[N];

int qpow(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

signed main() {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, res = 0;
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	f[0] = f[a[1]] = 1;
	rep(i, 2, n) {
		int sum = 0;
		rep(j, 1, a[i]) sum += f[j], sum %= mod;
//		cout << endl;
		res = (res + (qpow(2, i - 1) - 1) % mod - sum + mod) % mod;
//		cout << res << endl;
		dwn(j, 5000, a[i]) {
			f[j] += f[j - a[i]];
			f[j] %= mod;
		}
	}
	cout << res << endl;
	return 0;
}
