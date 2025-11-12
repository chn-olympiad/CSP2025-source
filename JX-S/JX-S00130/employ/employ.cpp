#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MAXN = 20;
const int mod = 998244353;

ll f[MAXN][1 << 19][MAXN];
int n, m, c[MAXN];
char buf[25];

void solve() {
	scanf("%d%d%s", &n, &m, buf + 1);
	for(int i = 1; i <= n; i++) scanf("%d", c + i);
	for(int i = 1; i <= n; i++) {
		for(int s = 0; s < (1 << n); s++) {
			if(s >> (i-1) & 1) continue;
			for(int j = 0; j <= n; j++) {
				int x = (buf[i] == '0') || (j >= c[i]);
				if(j + x <= n) (f[i][s | (1 << (i-1))][j + x] += f[i][s][j]) %= mod;
			}
		}
	}
	ll ans = 0;
	for(int i = n; i > max(0,n - m); i++) (ans += f[n][(1 << (n+1))-1][i]) %= mod;
	printf("%lld\n", ans);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	solve();
}