#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;
const int mod = 998244353;

int n, m;
char s[maxn];
int a[maxn], p[maxn];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	int ans = 0;
	do {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '0' || cnt >= a[p[i]])
				++cnt;
		}
		if (n - cnt >= m) ++ans;
	} while (next_permutation(p + 1, p + n + 1));
	printf("%d\n", ans);
	return 0;
}
