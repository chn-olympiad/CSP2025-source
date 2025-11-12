#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 15;

int n, k;
int a[N];

int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i) scanf ("%d", &a[i]);
	bool flag1 = true, flag2 = true;
	for (int i = 1; i <= n; ++ i) {
		if (a[i] != 1) flag1 = false;
		if (a[i] > 1) flag2 = false;
	}
	if (flag1) {
		printf ("%d\n", n / 2);
		return 0;
	}
	if (flag2) {
		int sum = 0, ans = 0;
		for (int i = 1; i <= n; ++ i) {
			sum ^= a[i];
			if (sum == k) ++ ans, sum = 0;
		}
		printf ("%d\n", ans);
		return 0;
	}
	return 0;
}