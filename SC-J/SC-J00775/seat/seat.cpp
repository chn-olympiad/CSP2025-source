#include <bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	int n,m,flag = 0;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int x = a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i] == x)
		{
			cout << ceil(1.0 * i / n) << " ";
			if (flag % 2 == 0)
			{
				if (i % n == 0)
				{
					cout << n;
				}
				else
				{
					cout << i % n;
				}
			}
			else
			{
				if (i % n == 0)
				{
					cout << 1;
				}
				else
				{
					cout << n + 1 - (i % n);
				}
			}
			return 0;
		}
		if (i % n == 0)
		{
			flag++;
		}
	}
	return 0;
}