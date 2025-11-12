#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, ans = -1;
struct Node {
	int x, y, z;
} a[N];

void dfs(int u, int now, int cnt1, int cnt2, int cnt3) {
	if (cnt1 > n / 2)	
		return;
	if (cnt2 > n / 2)
		return;
	if (cnt3 > n / 2)
		return;
	if (u == n + 1) {
		ans = max(ans, now);
		return;
	}
	dfs(u + 1, now + a[u].x, cnt1 + 1, cnt2, cnt3);
	dfs(u + 1, now + a[u].y, cnt1, cnt2 + 1, cnt3);
	dfs(u + 1, now + a[u].z, cnt1, cnt2, cnt3 + 1);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
		dfs(1, 0, 0, 0, 0);
		cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	int tt;
	cin >> tt;
	while (tt--) solve();
	return 0;
}
