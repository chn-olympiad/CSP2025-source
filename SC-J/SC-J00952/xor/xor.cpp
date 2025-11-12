#include <bits/stdc++.h>
using namespace std;

int a[500010], sa[500010], f[500010], g[1048576];
bool flag[1048576];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sa[i] = sa[i-1] ^ a[i];
	}
	flag[0] = true;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		flag[sa[i]] = true;
		if (flag[k^sa[i]])
			f[i] = g[k^sa[i]] + 1;
		g[sa[i]] = max(g[sa[i]^a[i]], f[i]);
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}