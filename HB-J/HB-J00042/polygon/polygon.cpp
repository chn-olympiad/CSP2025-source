#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a[5005], m[5005], cnt;
bool book[5005];

bool dp(int x) {
	int maxn = 0, sum = 0;
	if (x < 3) return 0;
	for (int i = 1; i <= x; i++) {
		maxn = max(maxn, a[m[i]]);
		sum += a[m[i]];
	}
	if (sum > maxn * 2) return 1;
	return 0;
}

void dfs(int x, int step, int sum) {
	m[step] = x;
	if (dp(step)) cnt++;
	for (int i = x + 1; i <= n; i++) {
		if (!book[i]) {
			book[i] = 1;
			dfs(i, step + 1, sum + a[i]);
			book[i] = 0;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	book[0] = 1;
	dfs(0, 0, 0);
	cout << cnt;
	return 0;
}

