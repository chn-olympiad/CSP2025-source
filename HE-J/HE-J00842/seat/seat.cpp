#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
int n, m, a[N], k, t;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= n ; j++)
			cin >> a[++k];
	t = a[1];
	sort(a + 1, a + k + 1, cmp);
	k = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				if(a[++k] == t)
				{
					cout << i << " " << j << "\n";
				}
			}
		}
		else
		{
			for(int j = n ; j >= 1 ; j--)
			{
				if(a[++k] == t)
				{
					cout << i << " " << j << "\n";
				}
			}
		}
	}
	return 0;
}
