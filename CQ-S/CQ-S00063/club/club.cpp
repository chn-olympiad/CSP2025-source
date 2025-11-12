#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 5;
int t, n;
int a[N][4];
long long ans;

void dfs (int dep, int cnt1, int cnt2, int cnt3, long long sum) {
	if (dep == n + 1) {
		ans = max (ans, sum);
		return ;
	}
	
	if (cnt1 + 1 <= n / 2) dfs (dep + 1, cnt1 + 1, cnt2, cnt3, sum + a[dep][1]);
	if (cnt2 + 1 <= n / 2) dfs (dep + 1, cnt1, cnt2 + 1, cnt3, sum + a[dep][2]);
	if (cnt3 + 1 <= n / 2) dfs (dep + 1, cnt1, cnt2, cnt3 + 1, sum + a[dep][3]);
}

int main () {

	ios::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);

	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= 3; ++j) cin >> a[i][j];
		dfs (1, 0, 0, 0, 0);
		cout << ans << '\n';
	}
	
	return 0;
}
