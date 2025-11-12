#include <iostream>

using namespace std;

int n, m;
int myc, a;
int rk;

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	rk = 1;
	cin >> myc;
	for (int i = 2; i <= n * m; ++ i) {
		cin >> a;
		if (a > myc) rk ++;
	}
	int l = rk / n + 1, h;
	if ((l - 1) * n == rk) l --;
	if (l % 2 == 1) {
		h = rk - n * (l - 1);
	} else {
		h = n + 1 - (rk - n * (l - 1));
	}
	cout << l << ' ' << h;
	return 0;
}