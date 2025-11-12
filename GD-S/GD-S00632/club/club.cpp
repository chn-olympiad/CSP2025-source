#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t_t, n, a[N][5], cnt[5];
priority_queue<int> q[5];
void solve() {
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= 3; i++) {
		cnt[i] = 0;
		while (!q[i].empty()) q[i].pop();
	}
	for (int i = 1; i <= n; i++) {
		int fi = 0, se = 0;
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
			if (a[i][j] >= a[i][fi]) {
				se = fi, fi = j;
			} else if (a[i][j] >= a[i][se]) {
				se = j;
			}
		}
		cnt[fi]++;
		ans += a[i][fi];
		q[fi].push(a[i][se] - a[i][fi]);
	}
	int id = 0;
	for (int i = 1; i <= 3; i++) {
		if (cnt[i] > n / 2) {
			id = i;
			break;
		}
	}
	if (id == 0) {
		cout << ans << '\n';
		return ;
	}
	while (cnt[id] > n / 2) {
		ans += q[id].top();
		q[id].pop();
		cnt[id]--;
	}
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t_t;
	while (t_t--) solve();
}
