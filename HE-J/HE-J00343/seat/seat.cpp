#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], score, p, x, y, r;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		int num;
		cin >> num;
		a[i] = -num;
	}
	score = a[1];
	sort(a + 1, a + 1 + n * m);
	for(int i = 1; i <= n * m; i++) {
		if(a[i] == score) {
			p = i;
			break;
		}
	}
	x = p / n;
	if(p % n != 0) x++;
	if(p % n == 0) {
		r = n;
	}else {
		r = p % n;
	}
	if(x % 2 == 0) {
		y = m - (r) + 1;
	} else {
		y = r;
	}
	cout << x << ' ' << y;
	return 0;
}
