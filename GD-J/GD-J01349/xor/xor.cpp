#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, a[500005], s[500005], ans;

int f(int l, int r) {
	for (int i = l; i <= r; i++) {
		for (int j = i; j < r; j++) {
			if ((s[i - 1] ^ k) == s[j]) return i;
		}
	}
	return l;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		s[i] = s[i - 1] ^ a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((s[i - 1] ^ k) == s[j]) {
				int t = f(i, j);
				if (i == t) {
					ans++;
					i = j;
				}
				else i = t - 1;
				break;
			}
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}
/*
4 2
2 1 0 3
*/
/*
4 0
2 1 0 3
*/
