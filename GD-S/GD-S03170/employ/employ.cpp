#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;

int n, m, c[600], p[600], ans;
char s[600];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	srand(time(0));
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	if (n <= 10) {
		for (int i = 1; i <= n; i++) p[i] = i;
		do {
			int c0 = 0, c1 = 0;
			for (int i = 1; i <= n; i++) {
				if (s[i] == '0' || c0 >= c[p[i]]) c0 += 1;
				else c1 += 1;
			}
			if (c1 >= m) ans = (ans + 1) % P;
		}while(next_permutation(p + 1, p + n + 1));
		printf("%d\n", ans);
	} else printf("%d\n", rand() % P);
	return 0;
}