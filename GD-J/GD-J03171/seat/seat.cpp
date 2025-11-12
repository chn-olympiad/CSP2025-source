#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[100] = {0}, r;
	cin >> r;
	a[0] = r;
	for (int i = 1; i < n * m; i++) cin >> a[i];
	sort(a, a + n * m, cmp);
	if (a[0] == r) {
		cout << 1 << ' ' << 1;
		return 0;
	}
	int x = 1, y = 1;
	for (int i = 1; i < n * m; i++) {
		if (y % 2){
			x++;
			if (x > n) {
				x = n;
				y++;
			}
		} else {
			x--;
			if (x == 0) {
				x = 1;
				y++;
			}
		}
		if (a[i] == r) {
			cout << y << ' ' << x;
		} 
	}
	return 0;
}
