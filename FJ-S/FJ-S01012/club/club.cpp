#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int n, a[100005][5];
struct node {
	int xb, cz;
};
vector <node> c[5];
bool cmp(node x, node y) {
	return x.cz < y.cz;
}

void init() {
	for (int i = 1; i <= 3; i++) c[i].clear();
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	init();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int Max = max(max(a[i][1], a[i][2]), a[i][3]);
		int x = 0;
		for (int j = 1; j <= 3; j++) {
			if (a[i][j] == Max) {
				x = j;
				break;
			}
		}
		int qwq = -1;
		for (int j = 1; j <= 3; j++) {
			if (j != x) {
				qwq = max(qwq, a[i][j]);
			}
		}
		c[x].push_back({i, a[i][x] - qwq});
		ans += a[i][x];
	}
	for (int i = 1; i <= 3; i++) {
		int len = c[i].size();
		if (len > n / 2) {
			sort(c[i].begin(), c[i].end(), cmp);
			for (int j = 0; j < (len - n / 2); j++) ans -= c[i][j].cz;
		}
	}
	cout << ans << endl;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int T; cin >> T;
	while (T--) {
		solve();
	} 
	return 0;
} 
