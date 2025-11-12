#include <bits/stdc++.h>
using namespace std;

inline long long read(void) {
	long long x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - 48, c = getchar();
	return x * f;
}

struct node {
	long long a, b, c;
} a[100005];

long long T, n, ans;
priority_queue<long long> _a, _b, _c;

int main(void) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--) {
		n = read();
		while (!_a. empty()) _a. pop();
		while (!_b. empty()) _b. pop();
		while (!_c. empty()) _c. pop();
		ans = 0;
		for (int i = 1; i <= n; i++) {
			a[i]. a = read(), a[i]. b = read(), a[i]. c = read();
			long long mx = max(a[i]. a, max(a[i]. b, a[i]. c));
			if (a[i]. a == mx) ans += a[i]. a, _a. push(max(a[i]. b - a[i]. a, a[i]. c - a[i]. a));
			else if (a[i]. b == mx) ans += a[i]. b, _b. push(max(a[i]. a - a[i]. b, a[i]. c - a[i]. b));
			else ans += a[i]. c, _c. push(max(a[i]. a - a[i]. c, a[i]. b - a[i]. c));
		}
		while (_a. size() > n / 2) ans += _a. top(), _a. pop();
		while (_b. size() > n / 2) ans += _b. top(), _b. pop();
		while (_c. size() > n / 2) ans += _c. top(), _c. pop();
		printf("%lld\n", ans);
	}
	return 0;
}
