/*
	For any non-negative integer, we know that it xors
	0 resultin' in itself, and it xors itself
	resultin' in 0.
	So if we make a pre-xor array s to represent that
	s[i] = a[1] xor a[2] xor ... xor a[i],
	we can get the range [i, r] as s[r] xor s[l - 1]
	(
	 s[r] xor s[l - 1]
	=a[1] xor ... xor a[r]  xor  a[1] xor ... xor a[l - 1]
	=0 xor a[l] xor ... xor a[r]
	=a[l] xor ... xor a[r]
	).
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 500005;
long long a[MAX], s[MAX], k;
int n, dp[MAX], p[MAX];
/* use dp to record the max number of the ranges*/
long long getw(int l, int r) {
	if (l > r) swap(l, r);
	return s[r] ^ s[l - 1];
}
int findpos(int x) {
	int pp = p[x - 1] + 1;
	if (getw(pp, x) != k) {
		for (int i = pp; i <= x; i++) {
			if (getw(i, x) == k) {
				return i;
			}
		}
		return pp;
	}
	return pp;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		s[i] = s[i - 1] ^ a[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int pos = findpos(i);
		if (getw(pos, i) != k) {
			dp[i] = dp[i - 1];
			p[i] = p[i - 1];
		} else {
			dp[i] = max(dp[i - 1], dp[pos - 1] + 1);
			p[i] = i;
		}
	}
	printf("%d", dp[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
