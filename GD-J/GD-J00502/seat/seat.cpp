#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int a[10000];
int b[20][20];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	k = n * m;
	for(int i = 0; i < k; i ++)
	{
		cin >> a[i];
	}
	int r = a[0];
	sort(a, a + k, cmp);
	int f = 0;
	for(int i = 1; i <= m; i ++)
	{
		if(i % 2 != 0)
		{
			for(int j = 1; j <= n; j ++)
			{
				b[i][j] = a[f ++];
			}
		}
		
		else
		{
			for(int j = n; j >= 1; j --)
			{
				b[i][j] = a[f ++];
			}
		}
	}
	
	for(int i = 1; i <= m; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			if(b[i][j] == r)
			{
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}
