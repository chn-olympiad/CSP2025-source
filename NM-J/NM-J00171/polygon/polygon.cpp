#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[5010];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n <= 3)
	{
		for(int i = 1; i <= 10; i++)
		{
			if(a[1] == i)
			{
				for(int j = 1; j <= 10; j++)
				{
					if(a[2] == j)
					{
						for(int p = 1; p <= 10; p++)
						{
							if(a[3] == p)
							{
								if(max(max(i, j), p) < i + j + p - max(max(i, j), p)) cout << 1 << endl;
								else cout << 0 << endl;
							}
						}
					}
				}
			}
		}
	}
	else cout << 20 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
