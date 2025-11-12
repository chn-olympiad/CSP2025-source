#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back

const int N = 1e5 + 7;
int T, n, a[N][3], p, maxn, ans, c[N], t, tmp;

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	for (cin >> T; T--; ans = 0) {
		vector<int> b[3];
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				cin >> a[i][j];
		for (int i = 1; i <= n; i++) {
			maxn = -1;
			for (int j = 0; j < 3; j++)
				if (maxn < a[i][j]) c[i] = maxn, maxn = a[i][j], p = j;
				else if (c[i] < a[i][j]) c[i] = a[i][j];
			b[p].pb(i), ans += maxn;
		}
		
		p = -1;
		for (int j = 0; j < 3; j++)
			if (2 * b[j].size() > n) p = j, t = b[j].size() - n / 2;
		if (!~p) { cout << ans << '\n'; continue; }
		
		vector<int> d; tmp = 0;
		for (int i : b[p]) d.pb(a[i][p] - c[i]);
		sort(d.begin(), d.end());
		for (int i = 0; i < t; i++) tmp += d[i];
		cout << ans - tmp << '\n';
	}
}
