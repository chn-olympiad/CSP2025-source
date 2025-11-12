#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[105], a1, grid[105][105];
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) cin >> a[i];
	a1 = a[1];
	sort(a + 1, a + n * m + 1);
	reverse(a + 1, a + n * m + 1); // 从高到低
	int c = 1, r = 0; // c是列，r是行 
	for (int i = 1; i <= n * m; i ++) {
		if (r == n + 1) r = n, c ++;
		if (c % 2) { // 奇数列从上往下 
			r ++;
			if (r == n + 1) r = n, c ++;
			grid[r][c] = a[i];
		} else { // 从下往上 
			r --;
			if (r == 0) r = 1, c ++;
			grid[r][c] = a[i];
		}
		if (a[i] == a1) {
			cout << c << ' ' << r << '\n';
			return ;
		}
	}
	return ;
}
int main(void) {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(0);
	cout.tie(nullptr) -> sync_with_stdio(0);
	solve();
	return 0;
} 
