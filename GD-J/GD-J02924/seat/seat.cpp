#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], num, len, pos, h, w, s;
bool cmp(int x, int y)
{
	return x > y;
}
int finder(int x)
{
	int l = 1, r = len, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] <= x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	len = n * m;
	for (int i = 1; i <= len; i++)
		cin >> a[i];
	num = a[1];
	sort(a + 1, a + len + 1, cmp);
	pos = finder(num);
	if (pos % n != 0)
	{
		s = pos - pos / n * n;
		h = pos / n + 1;
	}
	else
	{
		s = n;
		h = pos / n;
	}
	if (h % 2 == 1)
		w = s;
	else
		w = n - s + 1;
	cout << h << " " << w << endl; 
	return 0;
}
