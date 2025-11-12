#include <bits/stdc++.h>
using namespace std;
int n, a[5005], maxn;
long long sum;
int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		maxn = max (maxn, a[i]), sum += a[i];
	}
	if (n < 3) printf ("0");
	else if (n == 3) {
		if (sum > 2 * maxn) printf ("1");
	}
	return 0;
}
