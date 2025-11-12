#include <bits/stdc++.h>

int a[105], a1, n, m, idx, r, c;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	std::cin >> n >> m;
	for(int i = 1; i <= n*m; ++i) {
		std::cin >> a[i];
	}
	a1 = a[1];
	std::sort(a+1, a+n*m+1);
	for(int i = 1; i <= n*m; ++i) {
		if(a[i] == a1) {
			idx = n*m - i;
			break;
		}
	}
	r = idx / n + 1;
	if(r & 1) c = idx % n + 1;
	else c = m - idx % n;
	
	std::cout << r << ' ' << c;
	
	return 0;
}
