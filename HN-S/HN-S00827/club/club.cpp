#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 5;

int t, n, a[3], v[kMaxN], p[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	for (cin >> t; t--;) {
		cin >> n;
		priority_queue<int> q[3];
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[j];
				p[j] = j;
			}
			sort(p, p + 3, [](int x, int y) { return a[x] > a[y]; });
			v[i] = a[p[1]] - a[p[0]];
			q[p[0]].push(v[i]), ans += a[p[0]];
		}
		for (int i = 0; i < 3; i++) {
			for (; q[i].size() > n / 2; q[i].pop()) {
				ans += q[i].top();
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
