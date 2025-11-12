#include <bits/stdc++.h>
#define int long long

template<typename T> void read(T &x) {
	x = 0; char s = getchar();
	for (; !isdigit(s); ) s = getchar();
	for (; isdigit(s); s = getchar()) x = (x << 3) + (x << 1) + s - '0';
}

template<typename T> void ckmax(T &x, T y) { x = x > y ? x : y; }
template<typename T> void ckmin(T &x, T y) { x = x < y ? x : y; }
template<typename T> void ckadd(T &x, T y, T p) { x = (x + y) % p; }
template<typename T> void ckmul(T &x, T y, T p) { x = (x * y) % p; }

const int N = 5e2 + 7;
const int Mod = 998244353;

char s[N];

int c[N], mark[N], C[N];
int n, m, ans;

int check() {
	int cnt = 0; for (int i = 1; i <= n; i ++) if (s[i] == '0' || cnt >= C[i]) cnt ++;
	return n - cnt >= m;
}

void dfs(int dep) {
	if (dep > n) return ans += check(), void();
	for (int i = 1; i <= n; i ++)
		if (!mark[i]) {
			mark[i] = 1; C[dep] = c[i];
			dfs(dep + 1);
			mark[i] = 0; C[dep] = 0;
		}
}

int Check() { for (int i = 1; i <= n; i ++) if (s[i] == '0') return 0; return 1; }

int F(int n) {
	int res = 1; for (int i = 1; i <= n; i ++) ckmul(res, i, Mod);
	return res;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%lld%lld%s", &n, &m, s + 1); for (int i = 1; i <= n; i ++) scanf("%lld", &c[i]);
	if (Check()) return printf("%lld", F(n)), 0;
	dfs(1); printf("%lld\n", ans);
	
	return 0;
}
