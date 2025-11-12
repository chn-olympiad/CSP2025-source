#include <iostream>
#include <algorithm>
#include <vector>
#define INF32 1000000000
using namespace std;

int read() {
	int x = 0;
	char c = getchar();
	while (c < '0' or c > '9') {
		c = getchar();
	}
	while (c >= '0' and c <= '9') {
		x = x * 10 + (c & 15), c = getchar();
	}
	return x;
}

int n, a[100000][3], p[100000], tot[3];

void init() {
	tot[0] = tot[1] = tot[2] = 0;
	n = read();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			a[i][j] = read();
		}
	}
}

void calculate() {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int mx = max({a[i][0], a[i][1], a[i][2]});
		for (int j = 0; j < 3; ++j) {
			if (a[i][j] == mx) {
				p[i] = j;
				break;
			}
		}
		ans += mx, ++tot[p[i]];
	}
	if (max({tot[0], tot[1], tot[2]}) <= (n >> 1)) {
		printf("%d\n", ans);		
		return;
	}
	ans = 0;
	for (int j = 0; j < 3; ++j) {
		int t = 0;
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			int d = -INF32;
			for (int k = 0; k < 3; ++k) {
				if (j != k) {
					d = max(d, a[i][k] - a[i][j]);
				}
			}
			t += a[i][j], v.push_back(d);
		}
		sort(v.begin(), v.end(), greater<>());
		for (int i = 0; i < (n >> 1); ++i) {
			t += v[i];
		}
		ans = max(ans, t);
	}
	printf("%d\n", ans);
}

void solve() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while (t--) {
		init(), calculate();
	}
}

int main() {
	solve();
	return 0;
}