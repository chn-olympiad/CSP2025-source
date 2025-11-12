#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N][5], p[N], ans, n;

void dfs(int sum, int l, int k1, int k2, int k3) {
	if (l == n + 1 && k1 <= n / 2 && k2 <= n / 2 && k3 <= n / 2) {
		ans = max(ans, sum);
		return ;
	}
	if (l == n + 1) return;
	dfs(sum + a[l][1], l + 1, k1 + 1, k2, k3);
	dfs(sum + a[l][2], l + 1, k1, k2 + 1, k3);
	dfs(sum + a[l][3], l + 1, k1, k2, k3 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while (T--) {
		cin >> n;int tmp = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] == 0) tmp++;
			if (a[i][3] == 0) tmp++;
		}
		if (tmp == 2 * n) {
			sort(a[i] + 1, a[i] + 1 + n);
			int sum = 0;
			for (int j = 1; j <= n / 2; j ++) {
				sum += a[i][j];
				cout << sum;
			}
		}
		ans = -1;
		dfs(0, 1, 0, 0, 0);
		cout << ans << '\n';
	}
	return 0;
}
