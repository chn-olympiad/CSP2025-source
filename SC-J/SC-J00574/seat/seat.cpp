#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int h, l, a1, mc = 1;
	scanf("%d %d", &h, &l);
	scanf("%d", &a1);
	for (int i = 1; i < l * h; i++) {
		int a;
		scanf("%d", &a);
		if (a > a1)
			mc++;
	}
	if (mc == 1)
		printf("1 1");
	else if (mc == l * h)
		printf("%d %d", l, h);
	else {
		int y = mc / h;
		if (1.0 * mc / h > y)
			printf("%d ", ++y);
		else
			printf("%d ", y);
		if (y % 2 == 1) {
			if (mc % h == 0)
				printf("%d", h);
			else
				printf("%d", mc % h);
		} else {
			if (mc % h == 0)
				printf("1");
			else
				printf("%d", h - mc % h + 1);
		}
	}
	return 0;
}