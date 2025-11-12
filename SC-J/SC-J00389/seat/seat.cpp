#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000005];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int k = a[1];
	sort(a + 1, a + n * m + 1);
	int p = 0;
	for  (int i = 1; i <= n * m; i++)
		if (a[i] == k)
		{
			p = n * m - i + 1;
			break;
		}
	int cnt = 1, i = 1, j = 1, t = 1;
	while (cnt < p)
	{
		j += t;
		if (j > n)
			i++, j = n, t = -1;
		if (j <= 0)
			i++, j = 1, t = 1;
		cnt++;
	}
	cout << i << ' ' << j;
	
	return 0;
}