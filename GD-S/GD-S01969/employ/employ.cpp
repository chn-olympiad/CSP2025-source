#include <bits/stdc++.h>

#define il inline

#define dbg(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

using ll = long long;

const int N = 500, mod = 998244353;

char s[N + 5];
int n, m, c[N + 5];

namespace task1 {

void body() {
	int ans = 0;
	vector<int> p(n), d(n + 1);
	for (int i = 0; i < n; i++) p[i] = i + 1;
	do {
		for (int i = 1; i <= n; i++) d[p[i - 1]] = i;
//		for (int i = 1; i <= n; i++) dbg("%d ", d[i]);
		int sum = 0;
		for (int i = 1; i <= n; i++)
			if (s[i] == '0') sum++;
			else if (sum >= c[d[i]]) sum++;
		if (m <= n - sum) ans++;
//		dbg("%d\n", sum);
	} while (next_permutation(p.begin(), p.end()));
	printf("%d\n", ans);
}

}

void solve() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	if (n <= 10) task1::body();
	else {
		ll ans = 1;
		for (int i = 1; i <= n; i++)
			ans = ans * i % mod;
		printf("%lld\n", ans);
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int T = 1;
//	scanf("%d", &T);
	while (T--) solve();
	return 0;
}

/*
3 2
101
1 1 2
*/
