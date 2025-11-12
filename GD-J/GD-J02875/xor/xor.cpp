#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 5e6 + 5;
int n, k, ans = -1, x, t = 0;
int a[N], b[M];

void dfs(int x, int now, int cnt) {
	t++;
	if (now > n) {
		ans = max(ans, cnt);
		return;
	}
	if (t > n * n) return;
	if (ans > 0 && cnt > ans) return;
	if (x == k)
		dfs(a[now + 1], now + 1, cnt + 1);
	for (int j = now + 1; j <= n; ++j) {
		x ^= a[j];
		if (x == k)
			dfs(a[j + 1], j + 1, cnt + 1);	
 	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	dfs(a[1], 1, 0);
	cout << ans << endl;
	return 0;
} 
