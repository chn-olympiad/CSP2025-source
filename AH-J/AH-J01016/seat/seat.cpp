// AH-J01016

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL n, m, a, x, rk = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &a);
	for (LL i = 2; i <= n * m; i++) {
		scanf("%lld", &x);
		if (x > a) rk++;
	}
	LL r = rk / n + (rk % n != 0);
	LL c = rk % n;
	if (c == 0) c = n;
	if (r % 2 == 0) c = n + 1 - c;
	printf("%lld %lld\n", r, c);
	return 0;
}
