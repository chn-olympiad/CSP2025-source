#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tpi = pair<int, pair<int, int>>;

int n;
int a[100010][3];
int p[100010][3];

int cnt[3];
priority_queue<tpi> q[3];

int ans;

void add(int i, int j) {
	cnt[j]++;
	ans += a[i][j];
	for (int k : p[i]) {
		if (j == k) continue;
		q[j].push({a[i][k]-a[i][j], {i, k}});
		break;
	}
}

void clear() {
	ans = 0;
	for (int i = 0; i < 3; i++) {
		while (!q[i].empty()) q[i].pop();
		cnt[i] = 0;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		clear();
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			for (int j = 0; j < 3; j++) p[i][j] = j;
			sort(p[i], p[i]+3, [&](int x, int y) -> bool {
				return a[i][x] > a[i][y];
			});
		}
		for (int i = 1; i <= n; i++) {
			int mdlt = 0, pos = 0;
			for (int j : p[i]) {
				if (cnt[j] < n/2) {
					if (a[i][j] > mdlt) pos = j, mdlt = a[i][j];
				} else {
					if (!q[j].empty() && a[i][j]+q[j].top().first >= 0) {
						if (a[i][j]+q[j].top().first > mdlt) pos = j, mdlt = a[i][j]+q[j].top().first;
					}
				}
			}
			if (cnt[pos] < n/2) {
				add(i, pos);
			} else {
				if (!q[pos].empty() && a[i][pos]+q[pos].top().first >= 0) {
					int x = q[pos].top().second.first, y = q[pos].top().second.second;
					q[pos].pop(), cnt[pos]--, ans -= a[x][pos];
					add(x, y);
					add(i, pos);
				}
			}
		}
		printf("%d\n", ans);
	}
}
