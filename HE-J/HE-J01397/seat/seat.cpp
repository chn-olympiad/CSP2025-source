#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n, m, room[15][15], a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int R = a[1];
	for(int i = 1; i < n * m; i++)
	{
		for(int j = i + 1; j <= n * m; j++)
		{
			if(a[j] > a[i])
			{
				a[j] += a[i];
				a[i] = a[j] - a[i];
				a[j] -= a[i];
			}
		}
	}
	int x = 1;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(!(i % 2)) room[n - j + 1][i] = a[x++];
			else room[j][i] = a[x++];
		}
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(room[j][i] == R) cout << i << " " << j;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
