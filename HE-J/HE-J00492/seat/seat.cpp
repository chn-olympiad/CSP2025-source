#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m;
pair<int, int> a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i].first;
		if (i == 1)
			a[i].second = 114514;
		else
			a[i].second = -114514;
	}
	sort(a + 1, a + n * m + 1);
	int pos = 0;
	for (int i = 1, j = n * m; i <= n * m, j >= 1; i++, j--)
	{
		if (a[j].second == 114514)
			pos = i;
	}
	pos--;
	int r, c;
	c = pos / n;
	if (c % 2)
	{
		r = (c + n) % n;
	}
	else
	{
		r = (c + n) % n;
		r = (n - 1) - r;
	}
	cout << c + 1 << ' ' << r + 1 << endl;
	return 0;
}
