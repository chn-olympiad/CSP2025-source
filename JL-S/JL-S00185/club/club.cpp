#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[N][10];
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
				cin >> a[i][j];
		}
		for(int i = 1; i <= n; i++)
		{
			a[i][4] = 0;
			for(int j = 1; j <= 3; j++)
			{
				if(a[i][4] < a[i][j])
				{
					a[i][4] = max(a[i][4], a[i][j]);
					a[i][5] = j;
				}
			}
		}
		
		for(int i = 1; i <= n; i++)
		{
			a[n + 2][1] = 0;
			a[n + 2][2] = 0;
			a[n + 2][3] = 0;
			int minn = 2147483647;
			int minn1 = 2147483647;
			a[n + 1][i] = a[1][i];
			a[n + 2][i]++;
			for(int j = 2; j <= n; j++)
			{
				int g = n / 2;
				if(a[n + 2][a[j][5]] + 1 <= g)
				{
					a[n + 2][a[j][5]]++;
					a[n + 1][i] += a[j][4];
					if(minn > a[j][4])
					{
						minn1 = minn;
						minn = a[j][4];
					}
					else if(minn1 > a[j][4])
					{
						minn1 = a[j][4];
					}
				}
				else
				{
					if(a[j][4] > minn)
					{
						a[n + 1][i] = a[n + 1][i] - minn + a[j][4];
						if(a[j][4] > minn1)
						{
							minn = minn1;
							minn1 = a[j][4];
							
						}
						else
						{
							minn = a[j][4];
						}
					}
				}
			}
		}
		int maxn = a[n + 1][1];
		for(int i = 1; i <= 3; i++)
		{
			for(int j = 1; j <= 3; j++)
				if(maxn < a[n + 1][j])
					maxn = a[n + 1][j];
		}
		cout << maxn << endl;
	}
	return 0;
}
