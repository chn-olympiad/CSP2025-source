#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int xbb = a[1];
	for (int i = 1; i <= n * m; i++)
	{
		for (int j = i + 1; j <= n * m; j++)
		{
			if (a[i] < a[j])
				swap (a[i], a[j]);
		}
	}
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == xbb)
		{
			xbb = i;
			break;
		}
	}
	int lie = xbb / n;
	int hang = xbb % n;
	if (hang == 0)
		hang = n;
	if (hang != n)
		lie ++;
	if (lie % 2 == 1)
		cout << lie << " " << hang;
	else
		cout << lie << " " << m - hang + 1;
	return 0;
}
