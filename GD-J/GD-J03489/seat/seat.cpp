#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a1, a, o, cnt = 1, cnt1, s, p;
	scanf("%d%d%d", &n, &m, &a1);
	o = m * n;
	for (int i = 1; i < o; i++)
	{
		scanf("%d", &a);
		if (a > a1) cnt++;
	}
	p = cnt % n;
	if (p != 0)
	{
		cnt1 = cnt / n + 1;
		if (cnt1 % 2 == 0) s = n - p + 1;
		else s = p;
	}
	else
	{
		cnt1 = cnt / n;
		if (cnt1 % 2 == 0) s = 1;
		else s = n;
	}
	cout << cnt1 << " " << s;
	return 0;
}
