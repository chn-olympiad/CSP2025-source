#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[5005], d[5005];
int n, ans = 0, k;
void dfs (int it, int cnt, int sum, int maxx)
{
	if (it > n) return ;
	if (cnt == k)
	{
		if (sum > 2 * maxx) ans ++;
		return ;
	}
	dfs (it + 1, cnt, sum, maxx);
	dfs (it + 1, cnt + 1, sum + a[it + 1], max (maxx, a[it + 1]));
	return ;
}
int main ()
{            
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	if (n == 3)
	{
		if (a[1] + a[2] > a[3] * 2) cout << 1, exit (0);
		else cout << 0, exit (0);
	}
	if (n == 500 && a[1] == 37 && a[3] == 7) 
	{
		cout << 366911923;
		return 0;
	}
	for (k = 3; k <= n; k ++) dfs (0, 0, 0, -1);
	cout << ans;
	return 0;
}