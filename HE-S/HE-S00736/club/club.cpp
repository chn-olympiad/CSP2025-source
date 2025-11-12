#include <bits/stdc++.h>

using namespace std;

namespace michaele {

	#define rep(i, s, t) for (int i = s; i <= t; i ++)

	const int N = 210;

/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
1 0 0
2 0 0
3 0 0
4 0 0
2
10 9 8
4 0 0

*/	
	int n, a[N][3];
	int f[N][N][N];

	void solve () {
		cin >> n;
		bool okA = 1;
		rep (i, 1, n) {
			rep (j, 0, 2) cin >> a[i][j];
			if (a[i][1] != 0 || a[i][2] != 0) {
				okA = false;
			}
		}
		if (okA) {
			int ans = 0;
			vector <int> vec;
			rep (i, 1, n) vec.push_back (a[i][0]);
			sort (vec.begin (), vec.end (), [](int a, int b) { return a > b; });
			rep (i, 0, n / 2 - 1) ans += vec[i];
			cout << ans << '\n';
			return;
		}

		memset (f, -0x3f, sizeof f);
		f[0][0][0] = 0;

		rep (i, 1, n) rep (j, 0, min (n >> 1, i)) rep (k, 0, min (n >> 1, i)) {
			if (i - j - k > (n >> 1)) continue;
			auto &now = f[i][j][k];
			if (i - j - k) {
				now = max (now, f[i - 1][j][k] + a[i][0]);
			}
			if (j) now = max (now, f[i - 1][j - 1][k] + a[i][1]);
			if (k) now = max (now, f[i - 1][j][k - 1] + a[i][2]);
		}
		int ans = 0;
		rep (j, 0, n >> 1) rep (k, 0, n >> 1) {
			if (n - j - k > (n >> 1)) continue;
			ans = max (ans, f[n][j][k]);
		}
		cout << ans << '\n';

	}
	void Main () {
		int T;
		cin >> T;
		while (T --) {
			solve ();
		}

	}
}

int main () {
	// freopen ("Af/club4.in", "r", stdin);
	// freopen ("Af/test.out", "w", stdout);

	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	ios :: sync_with_stdio (0);
	cin.tie (0);

	michaele :: Main ();
	

	return 0;
}