#include<bits/stdc++.h>

const int N = 500 + 7, mod = 998244353;

int n, m, c[N], cc, cp;
char s[N];
int p[N];
long long ans = 0;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
		if (s[i] == '0')
			++cc;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]), cp += (c[i] == 0);
	if (n - std::max(cc, cp) < m){
		printf("0");
		return 0;
	}
	if (cc == 0) {
		ans = 1;
		for (int i = 1; i <= n; ++i)
			ans = ans * i % mod;
		printf("%lld", ans);
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	do {
		int r = 0;
		for (int i = 1, cnt = 0; i <= n; ++i) {
			if (s[i] == '0')
				++cnt;
			else {
				if (cnt < c[p[i]])
					++r;
				else
					++cnt;
			}
		}
		if (r >= m)
			++ans;
	} while (std::next_permutation(p + 1, p + n + 1));
	printf("%lld", ans);
	return 0;
}
