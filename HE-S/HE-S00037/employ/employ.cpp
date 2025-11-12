#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 998244353;
const int MAXN = 1010050;
int n, m, c[MAXN], p[MAXN];
char s[MAXN];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for(int i = 1;i <= n; i++) scanf("%d", &c[i]);
	for(int i = 1;i <= n; i++) p[i] = i;
	ll ans = 0;
	do {
		int ps = 0, bye = 0;
		bool ok = true;
		for(int i = 1; i <= n && ok; i++) {
			if (ps + bye >= c[p[i]]) {
				bye++;
			} else if (s[i] == '0') ps++;
			if (n - ps - bye < m) ok = false;
		}
		if (ok) ans = (ans + 1) % mod;
	}while(next_permutation(p + 1, p + n + 1));
	printf("%lld", ans);
	return 0;
} 
