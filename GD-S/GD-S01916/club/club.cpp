#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve();
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}
void solve() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> a(3, vector<pair<int, int>>(n));
	vector<vector<pair<int, int>>> c(n, vector<pair<int, int>>(3));
	vector<int> k(n), maxx(n), cnt(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[j][i].first;
			a[j][i].second = i;
			c[i][j].first = a[j][i].first;
			c[i][j].second = j;
			maxx[i] = max(maxx[i], a[j][i].first);
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		vector<pair<int, int>> b;
		b = a[i];
		sort(b.begin(), b.end());
		for (int j = n - 1; j >= n / 2; j--) {
			if (k[b[j].second] == 2) continue;
			if (b[j].first != maxx[b[j].second]) {
				k[b[j].second] = 1;
				continue;
			}
			ans += b[j].first;
			k[b[j].second] = 2;
			cnt[i]++;
		}
	}
	for (int i = 0; i < n; i++) cout << k[i] << " ";
	for (int i = 0; i < n; i++) {
		if (k[i] != 2) {
			vector<pair<int, int>> b;
			b = c[i];
			sort(b.begin(), b.end());
			for (int j = 2; j >= 0; j--) {
				if (cnt[b[j].second] >= n / 2) continue;
				ans += b[j].first;
				cnt[b[j].second]++;
				k[i] = 2;
				break;
			}
		}
	}
	cout << ans << "\n";
	return ;
}
