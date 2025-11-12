#include<bits/stdc++.h>
using namespace std;
int stu[105], room[15][15];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	 
	int n, m, r;
	cin >> n >> m >> stu[1];
	r = stu[1];
	for(int i = 2; i <= n * m; i ++)scanf("%d", &stu[i]);
	sort(stu + 1, stu + n * m + 1, cmp);
	int cnt = 1;
	for(int j = 1; j <= m; j ++)
	{
		for(int i = 1; i <= n; i ++)
		{
			room[i][j] = stu[cnt ++];
		}
	}
//	for(int i = 1; i <= n; i ++)
//	{
//		for(int j = 1; j <= m; j ++)
//		{
//			cout << room[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << r << endl; 
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			if(room[i][j] == r)
			{
				if(j & 1)
				{
					cout << j << ' ' << i << endl;
				}
				else cout << j << ' ' << n - i + 1 << endl;
			}
		}
	}
	return 0;
}
