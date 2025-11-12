#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m , r;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
		if (i == 0) {
			r = a[i];
		}
	}
	sort (a , a + n * m , greater<int>());
	for (int i = 0; i < n * m; i++) {
		if (a[i] == r) {
			r = i + 1;
		}
	}
	int c = 1;
	while (r >= n + 1) {
		r -= n;
		c++;
	}
	if (c % 2 == 0) {
		cout << c << ' ' << n + 1 - r;
	} else {
		cout << c << ' ' << r;
	}
	return 0;
}