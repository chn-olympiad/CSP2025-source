#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10; 
int t;
int n;
struct club
{
	int c1, c2, c3;
	int num;
	int c;
}a[N];
bool cmp (club x, club y)
{
	if (x.c1 != y.c1) return x.c1 > y.c1;
	if (x.c2 != y.c2) return x.c2 > y.c2;
	if (x.c3 != y.c3) return x.c3 > y.c3;
	return x.num < y.num;
}
signed main ()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	while (t --)
	{
		memset (a, 0, sizeof (a));
		scanf ("%lld", &n);
		int gre = n / 2;
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i].c1 >> a[i].c2 >> a[i].c3;
			a[i].num = i;
		}
		sort (a + 1, a + n + 1, cmp);
		int t1 = 0, t2 = 0, t3 = 0;
		for (int i = 1; i <= n; i ++)
		{
			t1 += a[i].c1, t2 += a[i].c2, t3 += a[i].c3;
			a[i].c = 1;
		}
		if (t1 >= t2 && t1 >= t3)
		{
			for (int i = n; i > n - gre; i --)
			{
				t1 -= a[i].c1;
				a[i].c = 0;
			}
			for (int i = 1; i <= n; i ++)
			{
				if (a[i].c == 0)
				{
					a[i].c = 1;
					if (a[i].c2 < a[i].c3)
					{
						a[i].c = 1;
						t2 -= a[i].c2;
					}
					else
						t3 -= a[i].c3;
				}
				else t2 -= a[i].c2, t3 -= a[i].c3;
			}
		}
		if (t2 >= t1 && t2 >= t3)
		{
			for (int i = n; i > n - gre; i --)
			{
				t2 -= a[i].c2;
				a[i].c = 0;
			}
			for (int i = 1; i <= n; i ++)
			{
				if (a[i].c == 0)
				{
					a[i].c = 1;
					if (a[i].c1 < a[i].c3)
					{
						a[i].c = 1;
						t1 -= a[i].c1;
					}
					else
						t3 -= a[i].c3;
				}
				else t1 -= a[i].c1, t3 -= a[i].c3;
			}
		}
		if (t3 >= t2 && t1 <= t3)
		{
			for (int i = n; i > n - gre; i --)
			{
				t3 -= a[i].c3;
				a[i].c = 0;
			}
			for (int i = 1; i <= n; i ++)
			{
				if (a[i].c == 0)
				{
					a[i].c = 1;
					if (a[i].c1 < a[i].c3)
					{
						a[i].c = 1;
						t1 -= a[i].c1;
					}
					else
						t2 -= a[i].c2;
				}
				else t1 -= a[i].c1, t2 -= a[i].c2;
			}
		}
		cout << t1 + t2 + t3; 
	}
	return 0;
}
//这个打字方式一看就是经常打游戏的人
//准确点来说一看就是经常用电脑打第五人格的人
//空格键是用来校准的
//铛~~~~~完美破译 
//114514
//sos sos sos sos 
//BABYMONSTER 回归大爆！！！ 
