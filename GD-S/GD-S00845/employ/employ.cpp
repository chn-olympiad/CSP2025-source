#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dwn(i, j, k) for(int i = (j); i >= (k); --i)
#define int long long
#define ull unsigned long long
#define endl '\n'

using namespace std;

constexpr int N = 5e2 + 7, mod = 998244353;

int c[N], p[N], a[N];

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
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, flag = 1, m;
	cin >> n >> m;
	rep(i, 1, n) {
		char w;
		cin >> w;
		a[i] = w - '0';
	}
	rep(i, 1, n) cin >> c[i], p[i] = i;
	int res = 0;
	do {
		int cnt = 0, fail = 0;
		rep(i, 1, n) {
			if(a[i] && fail < c[p[i]]) ++cnt;
			else ++fail;
//			cout << p[i] << ' ';
		}
//		cout << endl << cnt << endl;
		res += cnt >= m;
		res >= mod ? res -= mod : 0;
	} while(next_permutation(p + 1, p + 1 + n));
	cout << res << endl;
	return 0;
}
