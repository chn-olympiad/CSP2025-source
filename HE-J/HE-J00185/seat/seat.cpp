#include <iostream>
#include <algorithm>
int n, m, siz, scr;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::cin >> n >> m;
	siz = n * m;
	int a[siz], seat[n][m];
	for (int i = 0; i < siz; ++i)
		std::cin >> a[i];
	scr = a[0];
	sort(a, a + siz, std::greater<int>());
	for(int i = 0; i < siz; ++i) {
		if (a[i] == scr) {
			int t = i;
			int c, r;
			if ((i + 1) % n == 0) {
				c = (i + 1) / n;
				r = n;
			} else {
				c = ((i + 1) / n) + 1;
				r = (i + 1) % n;
			}
			if (c % 2 == 0)
				r = n - r + 1;
			std::cout << c << " " << r;
			break;
		}
	}
	return 0;
}
