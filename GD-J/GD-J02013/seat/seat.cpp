#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], ansa = 1, ansb, s;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
		cin >> a[i];
	s = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i ++)
	{
		if (ansa % 2 == 1)
			ansb ++;
		else
			ansb --;
		if (ansb > n)
		{
			ansa ++;
			ansb = n;
		}
		if (ansb < 1)
		{
			ansa ++;
			ansb = 1;
		}
		if (a[i] == s)
			break;
	}
	cout << ansa << " " << ansb;
	return 0;
}
