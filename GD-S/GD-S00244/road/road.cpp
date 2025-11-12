#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int a[100][100] = {};
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		a[x][y] = w;
		a[y][x] = w;
	}//将原图存到邻接矩阵中
	int gai[15][10005];//乡村造的城市
	int c[20];
	bool p; 
	for (int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		if (c[i] == 0)
			p = 1;
		for (int j = 1;j <= n;j ++)
			cin >> gai[i][j];
	}
	long long num = 0;
	if (p)//如果cj为0，那么直接将其中最短的相加 
	{
		
		for (int i = 1;i < n;i ++)
		{
			int minx = 10000;
			for (int j = 1;j <= n;j ++)
			{
				if (a[i][j] != 0)
					minx = min(a[i][j], minx);
			}
			num += minx;
		}
	}
	cout << num;
	return 0;
}
