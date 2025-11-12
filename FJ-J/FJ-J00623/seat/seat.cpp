#include <cstdio>
#include <algorithm>
#include <functional>

int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0 ; i < n*m ; i ++) {
		scanf("%d", &a[i]);
		a[i] = 100 - a[i];
	}
	int a1 = a[0];
	std::sort(a, a+n*m);
	int rpos = std::lower_bound(a, a+n*m, a1) - a;
	int r = rpos / n + 1;
	int c1 = r % n;
	int c = (r % 2 ? c1 + 1 : n-c1);
	printf("%d %d", r, c);
	return 0;
}
