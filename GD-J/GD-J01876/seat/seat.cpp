#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[105], rn;
int st[15][15];

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
	{
		cin >> a[i];
	}
	rn = a[1];
	sort(a + 1, a + (n * m) + 1, greater <int> ()); 
	
	int top = 0;
	for (int i = 1; i <= m; ++i)
	{
		if (i & 1)
		{
			for (int j = 1; j <= n; ++j)
			{
				st[i][j] = a[++top];
				if (st[i][j] == rn)
				{
					cout << i << " " << j;
					return 0; 
				}
			}
		}
		else
		{
			for (int j = n; j >= 1; --j)
			{
				st[i][j] = a[++top];
				if (st[i][j] == rn)
				{
					cout << i << " " << j;
					return 0; 
				}
			}
		}
	}
	
	return 0;
}
