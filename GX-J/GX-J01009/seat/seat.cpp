#include <iostream>
#include <algorithm>
using namespace std;
int n, m, pos1, pos2, a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	pos1 = a[1], pos2 = n * m;
	sort(a + 1, a + n * m + 1);
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= m; j++)
			{
				if (pos1 == a[pos2])
				{
					cout << i << " " << j;
					return 0;
				}
				pos2--;
			}
 		}
		else
		{
			for (int j = m; j; j--)
			{
				if (pos1 == a[pos2])
				{
					cout << i << " " << j;
					return 0;
				}
				pos2--;
			}
		}
	}
	return 0;
}
