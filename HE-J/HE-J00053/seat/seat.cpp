#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N], n, m, index_R = 1, r, c;

int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	
	std::ios::sync_with_stdio (false);
	std::cin.tie (nullptr);
	std::cout.tie (nullptr);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		std::cin >> a[i];
		if (a[i] > a[1]) {
			index_R ++;
		}
	}
	
	if (index_R % n == 0) {
		c = index_R / n;
	} else {
		c = index_R / n + 1;
	}
	
	if (c % 2 == 0) {
		if (index_R % n == 0) {
			r = 1;
		} else {
			r = n - (index_R % n) + 1;
		}
	} else {
		if (index_R % n == 0) {
			r = n;
		} else {
			r = index_R % n;
		}
	}
	
	std::cout << c << " " << r << "\n";
	return 0;
}
