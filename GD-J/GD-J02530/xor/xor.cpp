#include <bits/stdc++.h>
#define csp "xor"
using namespace std;
using LL = long long;
constexpr LL N = 5e5 + 10;
LL n, k, a[N], mx;
bool all1 = 1;
LL cnt0or1 = 0, cnt1;
void dfs(LL x, LL sum, LL d, bool in) {
	if(!in && x >= n) {
		if(a[n] == k) d ++;
		mx = max(mx, d);
		return ;
	}
	if(x >= n) return ;
	if(sum == k) {
		d ++;
		for(LL i = x + 1; i <= n; i ++) dfs(i, a[i], d, 1);
	}
	else if(in) for(LL i = x; i <= n; i ++) dfs(i, sum, d + 1, 0), sum ^= a[i];
}
void solve() {
	scanf("%lld%lld", &n, &k);
	for(LL i = 1; i <= n; i ++) scanf("%lld", a + i), all1 = all1 && a[i] == 1, cnt0or1 += (a[i] == 1 || a[i] == 0), cnt1 += a[i] == 1;
	if(n <= 1e2 && all1 && k == 0) {
		printf("%lld\n", n >> 1);
		return ;
	}
	if(n <= 2e5 && cnt0or1 == n && k <= 1) {
		printf("%lld\n", cnt1);
		return ;
	}
	for(LL i = 1; i <= n; i ++) dfs(i, a[i], 0, 1);
	printf("%lld\n", mx);
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
