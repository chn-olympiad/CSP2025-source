#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool cmp(int x, int y) {
	return x > y;
}
int a[N][4];
int f[N][4];

int main() {
	ios::sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a10 = true, a20 = true, a30 = true;
		vector<int> maxn;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			maxn.push_back(max(a[i][1], max(a[i][2], a[i][3])));
			if (a10 && a[i][1] >= 1) a10 = false;
			if (a20 && a[i][2] >= 1) a20 = false;
			if (a30 && a[i][3] >= 1) a30 = false;
		}
		if (n == 2) {
			int ans = -1;
			for (int i = 1; i <= 3; ++i) {
				for (int j = 1; j <= 3; ++j) {
					if (i == j) continue;
					ans = max(ans, a[1][i] + a[2][j]);
				}
			}
			cout << ans << "\n";
			continue;
		}
		if (n == 4) {
			int ans = -1;
			for (int i = 1; i <= 3; ++i) {
				for (int j = 1; j <= 3; ++j) {
					for (int k = 1; k <= 3; ++k) {
						for (int l = 1; l <= 3; ++l) {
							if (i == j && i == k) continue;
							if (i == j && i == l) continue;
							if (i == k && i == l) continue;
							if (j == k && j == l) continue;
							ans = max(ans, a[1][i] + a[2][j] + a[3][k] + a[4][l]);
						}
					}
				}
			}
			cout << ans << "\n";
			continue;
		}
		if ((a10 && a20) || (a10 && a30) || (a30 && a20)) {
			sort(maxn.begin(), maxn.end(), cmp);
			long long ans = 0;
			for (int i = 0; (i + 1) * 2 <= n; i++) {
				ans += maxn[i];
			}
			cout << ans << "\n";
			continue;
		}
		f[1][1] = a[1][1];
		f[1][2] = a[1][2];
		f[1][3] = a[1][3];
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) {
				f[i][j] = max(f[i - 1][1], max(f[i - 1][2], f[i - 1][3])) + a[i][j];
			}
		}
		int ans = -1;
		for (int i = 1; i <= 3; ++i) {
			ans = max(ans, f[n][i]);
		}
		cout << ans << "\n";
	}
	return 0;
}