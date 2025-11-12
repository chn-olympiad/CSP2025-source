#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct IO {
	IO() { freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout); }
	~IO() { fclose(stdin), fclose(stdout); }
} io;
int n, m, a[105], x;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) scanf("%d", a + i), x += a[1] <= a[i];
	int u = (x - 1) / n + 1, v = (x - 1) % n + 1;
	if (!(u & 1)) v = n - v + 1;
	printf("%d %d\n", u, v);
	return 0;
}