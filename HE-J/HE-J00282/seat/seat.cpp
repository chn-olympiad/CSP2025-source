#include<bits/stdc++.h>
using namespace std;
int n, m, s, ans;
int a[15][15];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
			if (i == 1 && j ==1) {
				s = a[i][j];
			} else if (a[i][j] > s) {
				ans ++;
			}
		}
	}
	if (ans == 0) {
		cout << "1 1" << '\n';
		return 0;
	}
	int i = 1, j = 1;
	while (ans) {
		while (i < n && ans) {
			ans --;
			i ++;
		}
		if (!ans) {
			cout << j << " " << i << '\n';
			return 0;  
		}
		j ++;
		ans --;
		if (!ans) {
			cout << j << " " << i << '\n';
			return 0;  
		}
		while (i > 1 && ans) {
			ans --;
			i --;
		}
		if (!ans) {
			cout << j << " " << i << '\n';
			return 0;  
		}
		j ++;
		ans --;
		if (!ans) {
			cout << j << " " << i << '\n';
			return 0;  
		}
	}
	return 0;
}
