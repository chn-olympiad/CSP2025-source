#include <bits/stdc++.h>
using namespace std;
int lt[10009][10009], n, m;//lt[i][j]表示从i到j的道路状态,0表示没路，1表示待修，2表示修好 
long long sum = 0;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		if(lt[x][y]==0) sum+=w;
		lt[x][y] = 1;
		lt[y][x] = 1; 
	}
	cout << sum;
	return 0;
}

