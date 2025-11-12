#include <bits/stdc++.h>
using namespace std;

#define FIONAME "replace"
char buf[5000010];
unsigned long long rules[10005][16];
const unsigned long long MODS[] = {0, 998244353ll, 1000000007ll, 0};
void rdstr (char* s) {
	while (1) {
		scanf ("%s", s);
		if (isalpha (s[0])) {
			return;
		}
	}
}

int main (void) {
	freopen (FIONAME ".in", "r", stdin);
	freopen (FIONAME ".out", "w", stdout);
	int n, q;
	scanf ("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		unsigned long long h1 = 0, h2 = 0;
		rdstr (buf + 1);
		//	h1
		int m = strlen (buf + 1);
		//	warning
		for (int j = 1; j <= m; ++j) {
			h1 *= 27;
			h1 += buf[j] - 'a' + 1;
			h1 %= MODS[1];
		}
		rdstr (buf + 1);
		for (int j = 1; j <= m; ++j) {
			h2 *= 27;
			h2 += buf[j] - 'a' + 1;
			h2 %= MODS[1];
		}
		rules[i][1] = (h1 + MODS[1] - h2) % MODS[1];
	}
	for (int i = 1; i <= q; ++i) {
		unsigned long long h3 = 0, h4 = 0;
		rdstr (buf + 1);
		//	h1
		int m = strlen (buf + 1);
		for (int j = 1; j <= m; ++j) {
			h3 *= 27;
			h3 += buf[j] - 'a' + 1;
			h3 %= MODS[1];
		}
		rdstr (buf + 1);
		for (int j = 1; j <= m; ++j) {
			h4 *= 27;
			h4 += buf[j] - 'a' + 1;
			h4 %= MODS[1];
		}
		unsigned long long res = (h3 + MODS[1] - h4) % MODS[1];
		unsigned long long fac = 1;
		unsigned long long ans = 0;
		for (int j = 1; j <= m; ++j) {
			fac = fac * 27 % MODS[1];
			for (int k = 1; k <= n; ++k) {
				if(fac * rules[k][1] % MODS[1] == res) {
					++ ans;
				}
			}
		}
		printf("%lld\n", ans);
		
	}
		
	return 0;
}
/*
27 * 480636170 mod 998244353  =1
*/
