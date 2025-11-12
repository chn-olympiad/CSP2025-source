#include <bits/stdc++.h>
using namespace std;
int n,m,a1;
int a[10005];
int s[105][105];
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
		if (i == 1)
		{
			a1 = a[i];
		}
	}
	sort(a + 1,a + n * m + 1);
	int num1 = 0;
	int num2 = 1;
	for (int i = 1;i <= n*m;i++)
	{
		if (a[i] == a1)
		{
			num1 = i;
			break;
		}
	}
	if (m % 2 == 1)
	{
		for (int i = m;i >= 1;i--)
		{
			if (i % 2 == 1)
			{
				for (int j = n;j >= 1;j--)
				{
					s[i][j] = a[num2];
					num2 ++;
					if (s[i][j] == a1)
					{
						cout << i << " " << j;
						break;
					}	
				}
			}
			else
			{
				for (int j = 1;j <= n;j++)
				{
					s[i][j] = a[num2];
					num2 ++;
					if (s[i][j] == a1)
					{
						cout << i << " " << j;
						break;
					}	
				}
			}
		}	
	}
	else
	{
		for (int i = m;i >= 1;i--)
		{
			if (i % 2 == 1)
			{
				for (int j = n;j >= 1;j--)
				{
					s[i][j] = a[num2];
					num2 ++;
					if (s[i][j] == a1)
					{
						cout << i << " " << j;
						break;
					}	
				}
			}
			else
			{
				for (int j = 1;j <= n;j++)
				{
					s[i][j] = a[num2];
					num2 ++;
					if (s[i][j] == a1)
					{
						cout << i << " " << j;
						break;
					}	
				}
			}
		}
	}
	return 0;	
} 
