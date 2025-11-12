#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int maxx = -2e9;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			if(a[i][j] > maxx) {
				maxx = a[i][j];
			}
		}
	}
	int p = maxx - a[0][0] + 1;
	int x = (p - 1) / n + 1;
	int y;
	if(x % 2 == 1) {
		int t = p % n;
		if(t == 0) {
			y = n;
		} else {
			y = t;
		}
	} else {
		int t = p % n;
		if(t == 0) {
			y = 1;
		} else {
			y = n - t + 1;
		}
	}
	cout << x << ' ' << y;
	return 0;
}
