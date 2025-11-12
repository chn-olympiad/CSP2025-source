#include <bits/stdc++.h>
#define csp "seat"
using namespace std;
using LL = long long;
constexpr LL N = 15;
LL n, m, nm, a[N], p, ans;
void solve() {
	scanf("%lld%lld", &n, &m), nm = n * m;
	for(LL i = 1; i <= nm; i ++) scanf("%lld", a + i);
	p = a[1];
	sort(a + 1, a + 1 + nm);
	p = nm - (lower_bound(a + 1, a + 1 + nm, p) - a - 1);
	reverse(a + 1, a + 1 + nm);
	ans = LL(ceil(1.0 * p / n));
	printf("%lld %lld\n", ans, ans & 1 ? (p - 1) % n + 1 : n - (p % n) + 1);
}
int main() {
	freopen(csp ".in", "r", stdin);
	freopen(csp ".out", "w", stdout);
//	LL t; scanf("%lld", &t); while(t --)
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
