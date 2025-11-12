#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 5;

int t, n, a[4], ans;
priority_queue<int, vector<int>, greater<int>> p[3];

void pu(int x, int y, int z) {
	ans += a[x];
	p[x].push(a[x] - max(a[y], a[z]));
	if (p[x].size() > n / 2) {
		ans -= p[x].top();
		p[x].pop();
	}
}

void clear(int x) {
	while (p[x].size())
		p[x].pop();
}

void solve() {
	cin >> n;
	ans = 0;
	clear(1), clear(2), clear(3);
	for (int i = 1; i <= n; i++) {
		cin >> a[1] >> a[2] >> a[3];
		if (a[1] >= a[2] && a[1] >= a[3]) 
			pu(1, 2, 3);
		else if (a[2] >= a[1] && a[2] >= a[3])
			pu(2, 1, 3);
		else
			pu(3, 2, 1);
	}
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (cin >> t; t; t--)
		solve();
	return 0;
}
