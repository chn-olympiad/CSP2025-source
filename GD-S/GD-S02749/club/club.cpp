#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn][5];
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	priority_queue<pair<int, int> > c1, c2, c3;
	for (int i = 1; i <= n; i ++) {
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			c1.push({-a[i][1], i});
		}
		else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
			c2.push({-a[i][2], i});
		}
		else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) {
			c3.push({-a[i][3], i});
		}
	}
	while (max(max(c1.size(), c2.size()), c3.size()) > (n >> 1)) {
		if (c1.size() > (n >> 1)) {
			int idx = c1.top().second;
			c1.pop();
			if (a[idx][2] >= a[idx][3] && c2.size() < (n >> 1))
				c2.push({-a[idx][2], idx});
			else
				c3.push({-a[idx][3], idx});
		}
		if (c2.size() > (n >> 1)) {
			int idx = c2.top().second;
			c2.pop();
			if (a[idx][3] >= a[idx][1] && c3.size() < (n >> 1))
				c3.push({-a[idx][3], idx});
			else
				c1.push({-a[idx][1], idx});
		}
		if (c3.size() > (n >> 1)) {
			int idx = c3.top().second;
			c3.pop();
			if (a[idx][1] >= a[idx][2] && c1.size() < (n >> 1))
				c1.push({-a[idx][1], idx});
			else
				c2.push({-a[idx][2], idx});
		}
	}
	int ans = 0;
	while (c1.size()) {
		ans -= c1.top().first;
		c1.pop();
	}
	while (c2.size()) {
		ans -= c2.top().first;
		c2.pop();
	}
	while (c3.size()) {
		ans -= c3.top().first;
		c3.pop();
	}
	cout << ans << endl;
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while (T --) solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
