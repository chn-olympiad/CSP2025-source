#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 17;
int i, j, k, l, r, m, n, p[N], c[N];
char s[N];
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d %s", &n, &m, s+1);
	for (i=1; i<=n; i++) scanf("%d", &c[i]);
	iota(p+1, p+n+1, 1);
	int ans = 0;
	do
	{
		k = 0;
		for (i=1; i<=n; i++) if (s[i] == '0' || k >= c[p[i]]) k++;
		if (n-k >= m) ans++;
	} while (next_permutation(p+1, p+n+1));
	printf("%d", ans);
}

