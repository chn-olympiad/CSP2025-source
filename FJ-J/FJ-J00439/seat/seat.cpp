#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, m, a[1005], b[1005], t[N][N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i ++ )
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n * m + 1);
	int idx = n * m;
	for (int i = 1; i <= m; i ++ )
	{
		if (i & 1)
		{
			for (int j = 1; j <= n; j ++ ) t[j][i] = b[idx -- ]; 
		}
		else
		{
			for (int j = n; j >= 1; j -- ) t[j][i] = b[idx -- ];
		}
	}
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= m; j ++ )
		{
			if (t[i][j] == a[1])
			{
				cout << j << " " << i << endl;
				return 0;
			} 
		}
	} 
	return 0;
} 

