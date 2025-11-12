#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
//3  xor
int n, k, a[N], cnt;
int sum (int l, int r) {
	int ret = 0;
	if (l == r) return a[l];
	for (int i = l; i <= r; i++) {
		ret += (a[i] ^ ret);
	}
	return ret;
}
int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int l = 1, r = n;
	while (l <= r) {
		if (sum(l, r) == k) {
			r--;
		}else l++;
	}
	printf("%d", cnt);
	return 0;
}
