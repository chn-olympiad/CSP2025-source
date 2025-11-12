#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 0, cnt = 0;
int a[5010], b[5010];
bool mark[5010];
void dfs(int l, int h) {
	if (l > k) {
		int sum = 0, ma = INT_MIN;
		for (int i = 1; i <= k; i++) {
			sum += b[i];
			ma = max(ma, b[i]);
		}
		if (sum > ma * 2) {
			ans = (ans + 1) % 998244353;
		}
		return;
	}
	for (int i = h + 1; i <= n; i++) {
		b[l] = a[i];
		dfs(l + 1, max(h, i));
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (k = 3; k <= n; k++) {
		dfs(1, 0);
	}
	printf("%d\n", ans);
	return 0;
}
