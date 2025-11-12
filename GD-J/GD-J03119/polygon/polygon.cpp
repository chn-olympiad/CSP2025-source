#include<bits/stdc++.h>
using namespace std;
const int N = 5000 + 10, mod = 998244353;
int a[N], c[N][N];
int solve()
{
	memset(c, 0, sizeof c); 
	int n, cnt1 = 0; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt1 += (a[i] == 1);
	
	c[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		c[i][1] = 1;
		for (int j = 2; j <= n; j++)
			c[i][j] = ((long long)c[i-1][j] + (long long)c[i-1][j-1]) % mod;
		cout << '\n';
	}
	
	if (cnt1 == n)//ÌØÊâÐÔÖÊ
	{
		int ans = 0;
		for (int i = 3; i <= n; i++) ans = ((long long)ans + (long long)c[n][i]) % mod;
		cout << ans;
	}
	return 0;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
When shadow fall across you world
and you enemy wants nothing but your annialation 
Where will you find allies
in desperate struggle for survival
~RETRIBUTION~ 
*/
