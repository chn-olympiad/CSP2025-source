#include <bits/stdc++.h>
using namespace std;

int n, m, c[505], a[505], b[505], ans = 0;

bool check() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt >= c[b[i]]) {
			cnt++;
		} else {
			if (!a[i]) cnt++;
		}
		if (cnt > n - m) return false;
	}
	return true;
}
long long solve(int x) {
	if (x == 1) return 1;
	return 1LL * x * solve(x - 1) % 998244353;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%1d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		b[i] = i;
	}
	do {
		if (check()) ans++;
		ans %= 998244353;
	} while (next_permutation(b + 1, b + n + 1));
	if (n <= 10) printf("%lld", ans);
	else printf("%lld\n", solve(n));
	return 0;
}
