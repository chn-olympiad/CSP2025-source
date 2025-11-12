#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int T, n;
int a[N][3], b[N], c[3];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	while (T--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
		for (int i = 1; i <= n; ++i) {
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
				b[i] = 0;
			}
			else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
				b[i] = 1;
			}
			else {
				b[i] = 2;
			}
			++c[b[i]];
			ans += a[i][b[i]];
		}
		if (c[0] > n / 2) {
			multiset<int> s;
			for (int i = 1; i <= n; ++i) {
				if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) s.insert(min(a[i][0] - a[i][1], a[i][0] - a[i][2]));
			}
			int k = 0;
			for (auto i : s) {
				if (k == c[0] - n / 2) {
					break;
				}
				ans -= i;
				++k;
			}
		}
		else if (c[1] > n / 2) {
			multiset<int> s;
			for (int i = 1; i <= n; ++i) {
				if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) s.insert(min(a[i][1] - a[i][0], a[i][1] - a[i][2]));
			}
			int k = 0;
			for (auto i : s) {
				if (k == c[1] - n / 2) {
					break;
				}
				ans -= i;
				++k;
			}
		}
		else if (c[2] > n / 2) {
			multiset<int> s;
			for (int i = 1; i <= n; ++i) {
				if (a[i][2] >= a[i][0] && a[i][2] >= a[i][1]) s.insert(min(a[i][2] - a[i][0], a[i][2] - a[i][1]));
			}
			int k = 0;
			for (auto i : s) {
				if (k == c[2] - n / 2) {
					break;
				}
				ans -= i;
				++k;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
