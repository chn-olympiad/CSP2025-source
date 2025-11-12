/*
就这样吧，考成____了 
*/ 
#include <bits/stdc++.h>
char s[20];
int c[20], per[20];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d%d%s", &n, &m, s);
	for (int i = 0; i < n; ++i) scanf("%d", c + i), per[i] = i;
	int ans = 0;
	do {
		for (int i = 0, pe = 0, givup = 0; i < n; ++i) {
			if (s[i] == '1' && givup < c[per[i]]) ++pe;
			else ++givup;
			if (pe == m) {++ans; break;}
		}
	} while (std::next_permutation(per, per + n));
	printf("%d\n", ans % 998244353);
}
