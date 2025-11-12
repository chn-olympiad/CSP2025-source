#include <bits/stdc++.h>
#define csp "polygon"
using namespace std;
using LL = long long;
constexpr LL N = 5e3 + 10;
LL n, a[N], cnt;
bool b[N];
void check() {
	LL mx = 0, sum = 0;
	for(LL i = 1; i <= n; i ++) if(b[i]) mx = max(mx, a[i]), sum += a[i];
	cnt += sum > (mx << 1);
	cnt = cnt % 998244353;
}
void dfs(LL x) {
	if(x > n) {
		check();
		return ;
	}
	dfs(x + 1);
	b[x] = 1;
	dfs(x + 1);
	b[x] = 0;
}
void solve() {
	scanf("%lld", &n);
	for(LL i = 1; i <= n; i ++) scanf("%lld", a + i);
	dfs(1);
	printf("%lld\n", cnt);
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
