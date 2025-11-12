#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;

int a[105];
int f[105];
bool cmp(int a, int b) {
	return a > b;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n * m; ++i) {
		scanf("%lld", &a[i]);
		if (i == 1) {
			f[a[i]] = 1;
		}
	}
	sort(a + 1, a + 1 + n*m, cmp);
	for (int i = 1, k = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j, ++k) {
			if (f[a[k]]) {
				if (i % 2 == 1) {
					printf("%lld %lld", i, j);
					return 0;
				} else {
					printf("%lld %lld", i, n - j + 1);
					return 0;
				}
			}
		}
	}
	return 0;
}
