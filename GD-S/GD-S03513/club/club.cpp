#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[100010][5];
long long ans;
vector<int> v[5];

bool check(int t) {
	for (int i = 1; i <= t; ++i) {
		if ((int)v[i].size() < n / 2) {
			return false;
		}
	}
	return true;
}

bool full(int i) {
	return (int)v[i].size() >= n / 2;
}

void dfs(int x, long long cnt, int t) {
	if (x > n) {
		ans = max(ans, cnt);
		return ;
	}
	for (int i = 1; i <= t; ++i) {
		if (full(i)) {
			if (check(t)) {
				ans = max(ans, cnt);
				return ;
			} else {
				continue;
			}
		} else {
			cnt += a[x][i];
			v[i].push_back(x);
			dfs(x + 1, cnt, t);
			v[i].pop_back();
			cnt -= a[x][i];
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		ans = 0;
		for (int i = 1; i <= 3; ++i) {
			v[i].clear();
		}
		cin >> n;
		bool flaga = true, flagb = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (a[i][2] != 0) {
				flaga = false;
			}
			if (a[i][3] != 0) {
				flagb = false;
			}
			if (!flaga && !flagb) {
				break;
			}
		}
		if (flaga) {
			int b[n + 5];
			for (int i = 1; i <= n; ++i) {
				b[i] = a[i][1];
			}
			sort(b + 1, b + 1 + n);
			for (int i = 1; i <= n / 2; ++i) {
				ans += b[n - i + 1];
			}
		} else if (flagb) {
			dfs(1, 0, 2);
		} else {
			dfs(1, 0, 3);
		}
		cout << ans << endl;
	}
	return 0;
} 
