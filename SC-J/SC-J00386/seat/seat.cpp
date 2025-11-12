#include <iostream>
#include <algorithm>
using namespace std;

int a[125];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int a1 = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				cnt++;
				if (a[cnt] == a1)
				{
					cout << i << " " << j;
				}
			}
		}
		if (i % 2 == 0)
		{
			for (int j = n; j >= 1; j--)
			{
				cnt++;
				if (a[cnt] == a1)
				{
					cout << i << " " << j;
				}
			}
		}
	}
	return 0;
} 