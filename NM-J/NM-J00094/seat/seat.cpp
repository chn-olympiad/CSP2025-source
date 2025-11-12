#include <bits/stdc++.h>
using namespace std;
int k = 1, n, m, a, s;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n * m - 1; i++) {
		cin >> a;
		// cout << a << " ";
		if (a > s) {
			k++;
		}
	}
	int c = 1, l = 1;
	for (int i = 2; i <= k; i++) {
		if (c % 2 == 0) {
			l--;
		}
		else {
			l++;
		}
		if (l < 1) {
            c++;
            l = 1;
		}
		else if (l > n) {
            c ++;
            l = n;
		}
	}
	cout << c << " " << l;
	return 0;
}
