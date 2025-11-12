#include<bits/stdc++.h>
using namespace std;
int n, m, ai, a1, num = 1, c, r;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%d", &a1);
	for(int i = 2; i <= n * m; i ++) {
		scanf("%d", &ai);
		if(ai > a1) {
			num ++;
		}
	}
	c = num / n;
	if(num % n != 0) {
		c ++;
	}
	r = num - ((c - 1) * n);
	if(c % 2 == 0) {
		r = n - r + 1;
	}
	printf("%d %d", c, r);
	return 0;
}
