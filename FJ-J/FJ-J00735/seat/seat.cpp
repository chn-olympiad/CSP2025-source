#include <bits/stdc++.h>
//#define int long long
using namespace std;

int n, m, row, col;
int a[105], cnt;

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i]; if (a[i] >= a[1]) cnt++;
	}
	col = (cnt + n - 1) / n;
	row = cnt - (col - 1) * n;
	if (~col & 1) row = n + 1 - row;
	cout << col << ' ' << row; 
}
