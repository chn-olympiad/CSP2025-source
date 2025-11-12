#include <iostream>
using namespace std;

int n, m, pos;
int a[110];
bool vis[110];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	a[0] = -1e9;
	
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n * m; i++)
	{
		int mxi = 0;
		for (int j = 1; j <= n * m; j++)
		{
			if (vis[j]) continue;
			if (a[j] > a[mxi])
				mxi = j;
		}
		vis[mxi] = 1;
		pos++;
		if (mxi == 1)
			break;
	}
	
	int c = (pos + n - 1) / n;
	int r = pos;
	r -= (c - 1) * n;
	if (c % 2 == 0)
		r = n - r + 1;
	
	cout << c << ' ' << r;
	
	return 0;
}
