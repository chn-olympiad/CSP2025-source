#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, ans = -1, o;
struct node
{
	int hp, team;
}a[100005][4];
void dfs (int it, int hg, int sum1, int sum2, int sum3)
{
	if (it == n + 1) 
	{
		ans = max (ans, hg);
		return ;
	}
	for (int i = 1; i <= 3; i ++)
	{
		if (a[it][i].team == 1 && sum1 < o) dfs (it + 1, hg + a[it][i].hp, sum1 + 1, sum2, sum3);
		if (a[it][i].team == 2 && sum2 < o) dfs (it + 1, hg + a[it][i].hp, sum1, sum2 + 1, sum3);
		if (a[it][i].team == 3 && sum3 < o) dfs (it + 1, hg + a[it][i].hp, sum1, sum2, sum3 + 1);
	}
	return ;
}
int main ()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t --)
	{
		ans = -1;
		cin >> n;
		o = n / 2;
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= 3; j ++)
			{
				cin >> a[i][j].hp;
				a[i][j].team = j;
			}
		}
		dfs (1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}