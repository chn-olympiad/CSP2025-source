#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int x = a[1], y;
	sort(a+1, a+n*m+1);
	int j = 1;
	for (int i = n*m; i >= 1; i--) {
		if (a[i] == x) {
			y = j;
			break;
		}
		j++;
	}
	int b = y / n;
	int c = y % n;
	if(b % 2 == 1) {
		if (c == 0) {
			cout << b << ' ' << n;
		} else {
			cout << b+1 << ' ' << n-c+1;
		}
	} else {
		if (c == 0) {
			cout << b << ' ' << 1;
		} else {
			cout << b+1 << ' ' << c;
		}
	}
	return 0;
}
