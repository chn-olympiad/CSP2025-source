#include <bits/stdc++.h>
using namespace std;
const int N = 5010, mod = 998244353, MX = 5001;
int n, a[N], tg[5][N], ans;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = a[i]+1; j <= MX; j++)
			ans = (ans+tg[2][j])%mod;
		for(int j = MX; j >= 1; j--)
		{
			int p = min(MX, j+a[i]);
			tg[2][p] = (tg[2][p]+tg[2][j]+tg[1][j])%mod;
		}
		tg[1][a[i]]++;
	}
	printf("%d", ans);
	return 0;
}
