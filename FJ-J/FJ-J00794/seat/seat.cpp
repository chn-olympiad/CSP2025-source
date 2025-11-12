#include <bits/stdc++.h>
using namespace std;
int R, n, m, flag = 0;
int a[15][15], s[105];
void dfs(int x, int y, int dep) {
	if (flag) return ;
	if (s[dep] == R) {
		cout << y << ' ' << x;
		flag = 1;
		return ;
	}
	a[x][y] = s[dep];
//	cout  << x << ' ' << y << '\n';
	if (y % 2 == 1) {
//		if (x < n) cout << "------1------\n";
//		else if (x == n && y < m) cout << "------2------\n";
		if (x < n) dfs(x + 1, y, dep + 1);
		else if (x == n && y < m) dfs(x, y + 1, dep + 1);
	} else {
//		if (x > 1) cout << "------3------\n";
//		else if (x == 1 && y < m) cout << "------4------\n";
		if (x > 1) dfs(x - 1, y, dep + 1);
		else if (x == 1 && y < m) dfs(x, y + 1, dep + 1);
	}
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
	}
	R = s[1];
	sort(s + 1, s + 1 + n * m, cmp);
	dfs(1, 1, 1);
//	cout << '\n';
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << a[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	return 0;
}
