#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5;
const ll MOD = 998244353;
int n, m;
char s[maxn + 5];
int c[maxn + 5];
int p[maxn + 5];
int vis[maxn + 5];
ll fac[maxn + 5];
ll ans = 0ll;
ll ksm(ll x, int p) {
	ll ans = 1ll;
	while (p) {
		if (p & 1) ans = ans * x % MOD;
		x = x * x % MOD;
		p >>= 1;
	}
	return ans;
}
void dfs(int i, int ly, int nly) {
	if (ly >= m) {
		int pos = i - 1; // [1,pos]录用了m个
		ans = (ans + fac[n - pos]) % MOD; // 其它任意
		return ;
	}
	if (i == n + 1){
		if (ly >= m) ans ++;
		return ;
	}
	for (int j = 1; j <= n; j ++) {
		if (vis[j]) continue;
		vis[j] = 1;
		if (nly >= c[j] || s[i] == '0') {
			dfs(i + 1, ly, nly + 1);
		} else {
			dfs(i + 1, ly + 1, nly);
		}
		vis[j] = 0;
	}
}
int main() { // baoli
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);
	fac[0] = 1ll;
	for (int i = 1;i <= n;i ++) fac[i] = (fac[i - 1] * (ll)i) % MOD;
	bool flag = true;
	for (int i = 1;i <= (int)strlen(s + 1);i ++) if (s[i] == '0') flag = false;
	if (flag) {
		ans = fac[n] % MOD;
	} else {
		dfs(1,0,0);
	}
	printf("%lld",ans);
	return 0;
}