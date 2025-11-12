#include <bits/stdc++.h>
using namespace std;

#define int long long
#ifndef LOCAL_TEST
#define endl '\n'
#endif

const int MAXN = 1e5 + 5;
int n, a[MAXN][4];

void work() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cin >> a[i][j];
		}
	}
	vector<int> c1, c2, c3;
	for (int i = 1; i <= n; ++i) {
		int m = max({a[i][1], a[i][2], a[i][3]});
		if (m == a[i][1]) {
			c1.push_back(i);
		} else if (m == a[i][2]) {
			c2.push_back(i);
		} else {
			c3.push_back(i);
		}
	}
	if ((int)c1.size() > n / 2) {
		sort(c1.begin(), c1.end(), [&](auto x, auto y) {
			return a[x][1] - max(a[x][2], a[x][3]) > a[y][1] - max(a[y][2], a[y][3]);
		});
		while ((int)c1.size() > n / 2) {
			int x = c1.back(); c1.pop_back();
			if (a[x][2] > a[x][3]) c2.push_back(x);
			else c3.push_back(x);
		}
	} 
	if ((int)c2.size() > n / 2) {
		sort(c2.begin(), c2.end(), [&](auto x, auto y) {
			return a[x][2] - max(a[x][1], a[x][3]) > a[y][2] - max(a[y][1], a[y][3]);
		});
		while ((int)c2.size() > n / 2) {
			int x = c2.back(); c2.pop_back();
			if (a[x][1] > a[x][3]) c1.push_back(x);
			else c3.push_back(x);
		}
	}
	if ((int)c3.size() > n / 2) {
		sort(c3.begin(), c3.end(), [&](auto x, auto y) {
			return a[x][3] - max(a[x][1], a[x][2]) > a[y][3] - max(a[y][1], a[y][2]);
		});
		while ((int)c3.size() > n / 2) {
			int x = c3.back(); c3.pop_back();
			if (a[x][1] > a[x][2]) c1.push_back(x);
			else c2.push_back(x);
		}
	}
	int ans = 0;
	for (auto x:c1) {
		ans += a[x][1];
	}
	for (auto x:c2) {
		ans += a[x][2];
	}
	for (auto x:c3) {
		ans += a[x][3];
	}
	cout << ans << endl;
}

signed main(void) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while (T--) work();
	return 0;
}
