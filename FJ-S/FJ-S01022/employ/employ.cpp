#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int MOD = 998244353;
int n, m, p[N], idx[N], ans, cnt;
char s[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]), idx[i] = i;
		if (p[i] > 0) {
			cnt++;
		}
	}
//	if (m == 1) {
//		if (s[1] == '0') {
//			printf("0");
//			return 0;
//		}
//		long long res = 1;
//		for (int i = 1; i < n; i++) res = res * i % MOD;
//		res = res * cnt % MOD;
//		printf("%lld", res % MOD);
//		return 0;
//	}
	do {
		int sum = 0, res = n;
		for (int i = 1; i <= n; i++) {
			if (sum >= p[idx[i]] || s[i] == '0') {
				res--, sum++;
			}
		}
		if (res >= m) {
			ans++;
		}
	} while (next_permutation(idx + 1, idx + n + 1));
	printf("%d", ans);
	return 0;
}
