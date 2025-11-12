#include <bits/stdc++.h>

using namespace std;

inline
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ '0');
		ch = getchar();
	}
	return x * f;
}

const int N = 1e5 + 7;

int t, n, a[N][5], ans;

inline
void dfs(int x, int num1, int num2, int num3, int s) {
	ans = max(ans, s);
	if (x > n) return ;
	if (num1 + 1 <= n / 2) dfs(x + 1, num1 + 1, num2, num3, s + a[x][1]);
	if (num2 + 1 <= n / 2) dfs(x + 1, num1, num2 + 1, num3, s + a[x][2]);
	if (num3 + 1 <= n / 2) dfs(x + 1, num1, num2, num3 + 1, s + a[x][3]);
}

inline
void solve() {
	n = read();
	ans = 0;
	if (n == 100000) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) a[i][j] = read();
			ans += max({a[i][1], a[i][2], a[i][3]});
		}
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) a[i][j] = read();
		}
		dfs(1, 0, 0, 0, 0);
	}
	printf ("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while (t--) solve();
	return 0;
}
