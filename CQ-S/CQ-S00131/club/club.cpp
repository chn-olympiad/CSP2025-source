#include<bits/stdc++.h>
#define LL long long
#define PLL pair<LL, LL>
#define PLI pair<LL, int>
#define PII pair<int, int>
using namespace std;
const int N = 1e5;
int a[N + 5][5], n, ans = 0;
void solve() {
	cin >> n; ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
	priority_queue<PII, vector<PII>, greater<PII> > q[4];
	for (int i = 1; i <= n; i++) {
		vector<PII> t(4);
		for (int j = 1; j <= 3; j++) t[j] = {a[i][j], j};
		sort(t.begin() + 1, t.end()); reverse(t.begin() + 1, t.end());
//		cout << t[1].first << " " << t[2].first << " i\n";
//		if (!q[t[1].seocnd].empty()) cout << q[t[1].second].top().
		if ((int)q[t[1].second].size() < n / 2) {
			q[t[1].second].push({t[1].first - t[2].first, i});
			ans += t[1].first;
		} else if (t[1].first - t[2].first > (int)q[t[1].second].top().first) {
			ans -= q[t[1].second].top().first; ans += t[1].first;
			q[t[1].second].pop();
			q[t[1].second].push({t[1].first - t[2].first, i});
		} else {
			ans += t[2].first;
		}
	}
	cout << ans << "\n";
}
signed main() {
//	freopen("club4.in", "r", stdin);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
