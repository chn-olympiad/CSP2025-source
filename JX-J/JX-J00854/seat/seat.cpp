#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + 1 + (n * m), cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= n; j++) {
				if (a[++cnt] == r) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				if (a[++cnt] == r) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
// luogu uid: 1277793
// 💯
