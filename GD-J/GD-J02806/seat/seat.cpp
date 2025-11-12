#include <iostream>
#include <algorithm>

int main(void) {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, s;
	std::cin >> n >> m;
	int a[105];
	for (int i = 1; i <= n * m; ++i) {
		std::cin >> a[i];
	}
	s = a[1];
	std::sort(a + 1, a + n * m + 1, std::greater<int>());
	
	int rk, c, r;
	for (int i = 1; i <= n * m; ++i) {
		if (a[i] == s) {
			rk = i;
			break;
		}
	}
	
	c = rk / n;
	if (rk % n) {
		++c;
	}
	r = rk % n;
	if (c % 2) {
		if (r == 0) {
			r = n;
		}
	} else {
		if (r == 0) {
			r = 1;
		} else {
			r = n - r + 1;
		}
	}
	
	std::cout << c << ' ' << r << '\n';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
