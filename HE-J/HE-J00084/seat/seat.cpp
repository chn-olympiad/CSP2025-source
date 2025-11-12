#include<bits/stdc++.h>
using namespace std;

int a[110];
int n, m, c, r, R, h;

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	R = a[1];
	for (int i = 1; i <= n * m; i --) {
		for (int j = n * m; j > i; j --) {
			if (a[j] > a[j - 1]) {
				h = a[j];
				a[j] = a[j - 1];
				a[j - 1] = h;
			}
		}
	}
	for (int i = 1; i <= n * m; i ++) {
		cout << a[i] << " ";
	}
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == R) {
			c = i / n;
			if (i % n != 0) {
				c += 1;
			}
			if (c % 2 == 1) {
				r = i % n;
				if (r == 0) {
					r = n;
				}
			}
			else {
				r = n - i % n + 1;
				if (i % n == 0) {
					r = 1;
				}
			}
			break;
		}
	}
	cout << c << " " << r;
	return 0;
}

