#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r, s = 1;
	scanf("%d %d %d", &n, &m, &r);
	for(int i = 1; i < n * m; ++ i) {
		int a;
		scanf("%d", &a);
		if(a > r) {
			s ++;
		}
	}
	int y = ceil(s * 1.0 / n);
	if(y % 2 == 0) {
		printf("%d %d", y, n - s + n * (y - 1) + 1);
	} else {
		printf("%d %d", y, s - n * (y - 1));
	}
	return 0;
}
