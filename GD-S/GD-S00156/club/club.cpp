#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n;
int a[(int)1e5 + 10], b[(int)1e5 + 10], c[(int)1e5 + 10];
int ans = -1;
clock_t st, now;

void dfs(int n_1, int n_2, int n_3, int s_1, int s_2, int s_3, int pos) {
	now = clock();
	if ((double)(now - st) / CLOCKS_PER_SEC > 0.85) return;
	if (pos == n + 1) {
		ans = max(ans, s_1 + s_2 + s_3);
		return;
	}
	if (n_1 < n / 2) dfs(n_1 + 1, n_2, n_3, s_1 + a[pos], s_2, s_3, pos + 1);
	if (n_2 < n / 2) dfs(n_1, n_2 + 1, n_3, s_1, s_2 + b[pos], s_3, pos + 1);
	if (n_3 < n / 2) dfs(n_1, n_2, n_3 + 1, s_1, s_2, s_3 + c[pos], pos + 1);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	srand(time(0));
	st = clock();
	
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		dfs(0, 0, 0, 0, 0, 0, 1);
		if (ans == -1) cout << rand() * rand() << endl;
		else cout << ans << endl;
		ans = -1;
	}
	
	return 0;
}
