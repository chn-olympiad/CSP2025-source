#include <bits/stdc++.h>
using namespace std;

struct Miao
{
	int x, y, z;
}a[100007];

bool cmp1(Miao x, Miao y)
{
	return x.x > y.x;
}

bool cmp2(Miao x, Miao y)
{
	return max(x.x, x.y) > max(y.x, y.y);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n, sum2 = 0, sum3 = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			sum2 += a[i].y;
			sum3 += a[i].z;
		}
		if (sum2 == 0 && sum3 == 0)
		{
			int sum = 0;
			sort(a, a + n, cmp1);
			for (int i = 0; i < n / 2; i++)
			{
				sum += a[i].x;
			}
			cout << sum;
		}
		else if (sum3 == 0)
		{
			sort(a, a + n, cmp2);
			int sum = 0, s = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i].x > a[i].y)
				{
					if (s < n / 2)
					{
						s++;
						sum += a[i].x;
					}
					else
					{
						sum += a[i].y;
					}
				}
				else
				{
					if (i - s > n / 2)
					{
						s++;
						sum += a[i].x;
					}
					else
					{
						sum += a[i].y;
					}
				}
			}
			cout << sum;
		}
		cout << endl;
	}
	return 0;
} 
