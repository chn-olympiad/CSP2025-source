#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int i, j, k, l, r, m, n, ans, a[3], c[3], p[N], b[N];
void solve()
{
	scanf("%d", &n);
	memset(c, 0, sizeof c);
	for (ans=0,i=1; i<=n; i++) 
	{
		for (j=0; j<3; j++) scanf("%d", &a[j]);
		for (j=k=0; j<3; j++) if (a[j] > a[k]) k = j;
		ans += a[k], c[k]++, p[i] = k;
		for (b[i]=1e9,j=0; j<3; j++) if (j != k) b[i] = min(b[i], a[k]-a[j]);
	}
	for (k=-1,j=0; j<3; j++) if (c[j] > n/2) k = j;
	if (k >= 0)
	{
		for (i=1; i<=n; i++) if (p[i] != k) b[i] = 1e9;
		sort(b+1, b+n+1);
		for (i=1; i<=c[k]-n/2; i++) ans -= b[i];
	} 
	printf("%d\n", ans);
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) solve();
}

