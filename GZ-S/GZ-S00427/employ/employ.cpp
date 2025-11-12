// GZ-S00427 °²Ë³¶þÖÐ ÕÔÑØ¿­
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = (a); i <= (b); ++ i)

const int N = 510, MOD = 998244353;
int n, m, s[N], c[N], p[N];
char s1[N];

void sub0() {
	scanf("%lld%lld", &n, &m);
	scanf("%s", s1 + 1);
	FOR(i, 1, n) s[i] = s1[i] - '0', p[i] = i; //printf("s[%lld] = %lld\n", i, s[i]);
	FOR(i, 1, n) scanf("%lld", &c[i]);
	int ans = 0;
	do {
		int cnt = 0, kkk = 0;
		FOR(i, 1, n) {
			if(kkk >= c[p[i]]) {
				kkk ++;
				continue;
			}
			if(s[i]) cnt ++;
			else kkk ++;
		}
		if(cnt >= m) ans = (ans + 1) % MOD;
	} while(next_permutation(p + 1, p + n + 1));
	printf("%lld\n", ans);
}

signed main() {
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	sub0();
	return 0;
}
