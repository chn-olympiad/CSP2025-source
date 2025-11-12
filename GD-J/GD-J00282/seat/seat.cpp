#include <iostream>
#include <algorithm>
using namespace std;
int a[105];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + (n * m) + 1, cmp);
	int cur = 1;
	for(int i = 1; i <= m; i++)//列
	{
		if(i % 2 != 0)
		{
			for(int j = 1; j <= n; j++)//奇数列 从1到n 
			{
				if(a[cur] == r)
				{
					cout << i << " " << j;
					return 0;
				}
				cur++;
			}
		}
		else
		{
			for(int j = n; j >= 1; j--)//偶数列 从n到1
			{
				if(a[cur] == r)
				{
					cout << i << " " << j;
					return 0;
				}
				cur++;
			}
		}
	}
	return 0;
}
