#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
struct sc
{
	int sco;
	bool f = 0;
	int y, x;
	
}a[110];
bool cmp (sc x, sc y)
{
	return x.sco > y.sco;
}
signed main ()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
		cin >> a[i].sco;
	a[1].f = 1;
	sort (a + 1, a + n * m + 1, cmp);
	int i = 1;
	for (int c = 1; c <= m; c ++)
	{
		if (c % 2 != 0)
		{
			for (int r = 1; r <= n; r ++)
		 	{
		 		a[i].y = c, a[i].x = r;
		 		i ++;
			}
		}
	 	else
	 	{
	 		for (int r = n; r > 0; r --)
		 	{
		 		a[i].y = c, a[i].x = r;
		 		i ++;
			}
		}
	}
	for (int i = 1; i <= n * m; i ++)
	{
		if (a[i].f)
		{
			cout << a[i].y << " " << a[i].x;
			return 0;
		}
	}
	return 0;
}
//第五人格，启动！！！ 
