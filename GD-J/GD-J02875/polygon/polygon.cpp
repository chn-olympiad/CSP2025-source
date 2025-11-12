#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int n, sum = 0, maxn = INT_MIN, ans = -1;
int a[N];

void dfs(int now, int cnt, int m) {
	if (now > n) {
		ans = max(ans, cnt);
		return;
	}
	if (ans > 0 && cnt > ans) return;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
		maxn = max(maxn, a[i]);
	}
	if (n <= 3) {
		if (sum > maxn * 2) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	dfs(1, 0, 3);
	cout << ans << endl;
	return 0;
} 
