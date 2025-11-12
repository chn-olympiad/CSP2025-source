#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[10][N], ans;
int b[10][N], n;
inline void dfs(int step, int res, int cnt) {
	if (cnt > n / 2 || n - step + 1 + cnt < n / 2) {
		return;
	}
	if (step == n + 1) {
		ans = max(ans, res);
		return;
	}
	for (int i = 1; i <= n; i++) {
		dfs(step + 1, res + b[i][1], cnt + 1);
		dfs(step + 1, res + b[i][2], cnt);
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			if (a[1][i] >= a[2][i] && a[1][i] >= a[3][i]) {
				b[1][i] = a[1][i];
				if (a[2][i] >= a[3][i]) {
					b[2][i] = a[2][i];
				} else {
					b[2][i] = a[3][i];
				}
			}
			if (a[2][i] >= a[1][i] && a[2][i] >= a[3][i]) {
				b[1][i] = a[2][i];
				if (a[1][i] >= a[3][i]) {
					b[2][i] = a[1][i];
				} else {
					b[2][i] = a[3][i];
				}
			}
			if (a[3][i] >= a[2][i] && a[3][i] >= a[1][i]) {
				b[1][i] = a[3][i];
				if (a[2][i] >= a[1][i]) {
					b[2][i] = a[2][i];
				} else {
					b[2][i] = a[1][i];
				}
			}
		}
		//反正只有最大和次大有用，那么我们就可以只记录最大和次大 
		if (n <= 10) {
			dfs(1, 0, 0);
			cout << ans << "\n";
			ans = 0;
			continue;
		}
	}
	return 0;
}

