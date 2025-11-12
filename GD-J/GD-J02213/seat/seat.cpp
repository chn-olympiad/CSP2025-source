#include <cstdio>

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r;
	scanf("%d%d%d", &n, &m, &r);
	
	int tmp, cnt = 0;
	for (int i = 0; i < n * m - 1; i++) {
		scanf("%d", &tmp);
		if (tmp > r) cnt++;
	}
	
	int ans;
	if ((cnt + 1) % n  == 0) {
		printf("%d ", (cnt + 1) / n);
		ans = (cnt + 1) / n;
	} else {
		printf("%d ", (cnt + 1) / n + 1);
		ans = (cnt + 1) / n + 1;
	}
	
	if ((cnt + 1) % n == 0) {
		printf("%d", n);
		return 0;
	} else if (ans % 2 == 0) {
		printf("%d", n + 1 - (cnt + 1) % n);
	} else if (ans % 2 != 0) {
		printf("%d", (cnt + 1) % n);
	}
	
	return 0;
} 
