#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
const int N = 510;
int n, m, a[N], c[N], f[N][N];
char s[N];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		a[i] = i;
	}
	if (m == n) {
		int cnt = 0, val = 0;
		for (int i = 1; i <= n; ++i) {
			cnt += c[i] == 0;
			val += s[i] == '1';
		}
		if (val < n || cnt) {
			puts("0");
			fclose(stdin), fclose(stdout);
			return 0;
		}
		int ans = 1;
		for (int i = 2; i <= n; ++i)
			ans = ans * i % MOD;
		printf("%lld\n", ans);
		fclose(stdin), fclose(stdout);
		return 0;
	}
	int ans = 0;
	do {
		int cnt = 0, tot = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '0' || c[a[i]] <= cnt) {
				++cnt;
				continue;
			}
			++tot;
		}
		if (tot >= m) (++ans) %= MOD;
	} while (next_permutation(a + 1, a + n + 1));
	printf("%lld\n", ans);
	fclose(stdin), fclose(stdout);
	return 0;
}