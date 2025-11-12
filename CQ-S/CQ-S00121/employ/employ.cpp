#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

int n, m;
char s[550];
int c[550];

int p[550];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	for (int i = 1; i <= n; i++) scanf("%d", c+i);
	for (int i = 1; i <= n; i++) p[i] = i;
	int ans = 0;
	do {
		int giveup = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (giveup >= c[p[i]]) giveup++;
			else {
				if (s[i] == '0') giveup++;
				else cnt++;
			}
		}
		if (cnt >= m) ans++;
	} while (next_permutation(p+1, p+n+1));
	printf("%d", ans);
}
