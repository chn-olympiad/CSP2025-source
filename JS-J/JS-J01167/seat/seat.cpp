#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[1001] = {0};
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int R = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int pos;
	for (int i = 1; i <= n * m; i++)
		if (a[i] == R)
		{
			pos = i - 1;
			break;
		}
	int r, c;
	c = pos / n + 1;
	if (c % 2 == 0)
		r = n - pos % n;
	else
		r = pos % n;
	cout << c << ' ' << r << endl;
	return 0;
}
