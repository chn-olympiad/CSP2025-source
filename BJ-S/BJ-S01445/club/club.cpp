#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int T, n, ans, a[N], c[N], cnt[5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n; ans = 0;
	//	cerr << n << "\n";
		memset(cnt, 0, sizeof(cnt));
		for (int i=1; i<=n; ++i) {
			int op, mx = -1, se = -1;
			for (int j=1; j<=3; ++j) {
				int x; cin >> x;
				if (mx < x) se = mx, op = j, mx = x;
				else if (se < x) se = x;
			}
			c[i] = op, ans += mx, ++cnt[op], a[i] = mx - se;
		}
		if (*max_element(cnt + 1, cnt + 4) <= n / 2) {
	//		cerr << "yes\n";
			cout << ans << "\n"; continue;
		}
	//	cerr << "no\n";
		int id = max_element(cnt + 1, cnt + 4) - cnt;
		vector<int> gap;
		int num = cnt[id] - n / 2;
		for (int i=1; i<=n; ++i)
			if (c[i] == id) gap.push_back(a[i]);
		sort(gap.begin(), gap.end());
		for (int i=0; i<num; ++i) ans -= gap[i];
		cout << ans << "\n";
	}
	return 0;
}