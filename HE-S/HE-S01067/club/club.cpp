#include <bits/stdc++.h>
using namespace std;
const int A = 1e5 + 10, B = 1e1 + 10;
struct C
{
	int a1, a2, a3;
} a, a1[A], a2[A], a3[A];
bool cmp1(C x, C y)
{
	return x.a1 - max(x.a2, x.a3) < y.a1 - max(y.a2, y.a3);
}
bool cmp2(C x, C y)
{
	return x.a2 - max(x.a1, x.a3) < y.a2 - max(y.a1, y.a3);
}
bool cmp3(C x, C y)
{
	return x.a3 - max(x.a1, x.a2) < y.a3 - max(y.a1, y.a2);
}
int ans, m1, m2, m3, n, t;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t --)
	{
		cin >> n, ans = m1 = m2 = m3 = 0;
		for (int i = 1; i <= n; i ++)
		{
			cin >> a.a1 >> a.a2 >> a.a3;
			if (a.a1 > a.a2 && a.a1 > a.a3)
				a1[++ m1] = a;
			else if (a.a2 > a.a3)
				a2[++ m2] = a;
			else
				a3[++ m3] = a;
		}
		if (m1 > n / 2)
		{
			sort(a1 + 1, a1 + m1 + 1, cmp1);
			for (int i = 1; i <= m1 - n / 2; i ++)
				ans -= a1[i].a1 - max(a1[i].a2, a1[i].a3);
		}	
		else if (m2 > n / 2)
		{
			sort(a2 + 1, a2 + m2 + 1, cmp2);
			for (int i = 1; i <= m2 - n / 2; i ++)
				ans -= a2[i].a2 - max(a2[i].a1, a2[i].a3);
		}
		else if (m3 > n / 2)
		{
			sort(a3 + 1, a3 + m3 + 1, cmp3);
			for (int i = 1; i <= m3 - n / 2; i ++)
				ans -= a3[i].a3 - max(a3[i].a1, a3[i].a2);
		}
		for (int i = 1; i <= m1; i ++)
			ans += a1[i].a1;
		for (int i = 1; i <= m2; i ++)
			ans += a2[i].a2;
		for (int i = 1; i <= m3; i ++)
			ans += a3[i].a3;
		cout << ans << '\n';
	}
	return 0;
}
