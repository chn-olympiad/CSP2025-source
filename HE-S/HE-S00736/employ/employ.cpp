#include <bits/stdc++.h>

using namespace std;

namespace michaele {

	#define rep(i, s, t) for (int i = s; i <= t; i ++)
	typedef long long ll;

	const int N = 20;

	int n, m;
	char s[N];
	int a[N], p[N];

	bool vis[N];
	int ans = 0;

	void dfs (int pos) {
		if (pos > n) {
			int cnt = 0, nos = 0;
			for (int i = 1; i <= n; i ++) {
				if (nos < a[p[i]] && s[i] == '1') cnt ++;
				else nos ++;
			}
			if (cnt >= m) ans ++;
			return;
		}

		for (int i = 1; i <= n; i ++) {
			if (!vis[i]) {
				vis[i] = 1;
				p[pos] = i;
				dfs (pos + 1);
				vis[i] = 0;
			}
		}
	}
/*

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
	void solve () {
		cin >> n >> m;
		cin >> (s + 1);
		
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		dfs (1);
		cout << ans << '\n';
	}

}
int main () {
	// freopen ("Cf/replace2.in", "r", stdin);
	// freopen ("Cf/test.out", "w", stdout);
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);

	michaele :: solve ();
	

	return 0;
}