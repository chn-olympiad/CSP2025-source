#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 501000;

int n, k, a[N], s[N];

bool check(ll dep, int st) {
	if (dep == 0) return true;
	if (st == n + 1) return false;
	for (int j = st; j <= n; j++)
		for (int i = st; i <= j; i++) if ((s[j] ^ s[i - 1]) == k) {
			return check(dep - 1, j + 1);
		}
	return false;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] ^ a[i];
	}
	ll L = 0, R = n * (n + 1) / 2;
	while (L < R) {
		ll M = (L + R + 1) >> 1;
		if (check(M, 1)) L = M;
		else R = M - 1;
	}
	printf("%lld\n", L);
	return 0;
}