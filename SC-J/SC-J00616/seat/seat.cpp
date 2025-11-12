#include <bits/stdc++.h>
using namespace std;
int a[101];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int r = a[1];
	sort(a + 1, a + n*m + 1, [](int a, int b) {
		return b < a;
	});
	int pos = lower_bound(a + 1, a + n*m + 1, r, [](int a, int b) {
		return b < a;
	}) - a;
	int c = (pos + n - 1) / n;
	r = (c % 2 ? (pos % n == 0) ? n : pos % n//顺着
	     : (pos % n == 0) ? 1 : n - pos % n + 1);//倒着
	printf("%d %d", c, r);
}