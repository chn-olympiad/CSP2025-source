#include <bits/stdc++.h>
using namespace std;

struct S
{
	int x;
	int y;
}a[1005];

int main ()
{
//	freopen ("xor.in" , "r" , stdin);
//	freopen ("xor.out" , "w" , stdout);
	int n , k;
	int cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x;
		if (a[i].x == k)
		{
			a[i].y = 1;
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int num = a[i].x;
		if (a[i].y == 0)
		{
			a[i].y = 1;
			for (int j = i + 1; j <= n; j++)
			{
				if (a[j].y == 0)
				{
					a[j].y = 1;
					num = num ^ a[j].x;
					if (num == k)
					{
						cnt++;
					}
				} 
				else
				{
					for (int k = i; k <= j - 1; k++)
					{
						a[k].y = 0;
					}
					break;
				}
			}
		}
	}
	cout << cnt;

	return 0;
} 
