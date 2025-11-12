#include <bits/stdc++.h>
using namespace std;
int n, cnt, m;
int a[5005];
int vis[5005];
void dfs(int dep, int maxn, int sum, int lst) {
	if (dep == m) {
		if (sum > maxn * 2) cnt++;
		return;
	}
	for (int i = lst + 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(dep + 1, max(maxn, a[i]), sum + a[i], i);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 3; i <= n; i++) {
		m = i;
		dfs(0, 0, 0, 0);
	}
	cout << cnt;
	return 0;
}
// max score: 10/25 -> 40/100
