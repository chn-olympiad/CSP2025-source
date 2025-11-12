#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int a[MAXN * MAXN];
int mp[MAXN][MAXN];
int ind;
int n;
int m;
int my = 0;

void operate(int i, int j)
{
	mp[i][j] = a[++ind];
	
	if(mp[i][j] == my)
	{
		cout << j << ' ' << i << endl, exit(0);
	}
}

int main()
{
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i], my = i == 1 ? a[i] : my;
	}
	sort(a + 1, a + n * m + 1, greater<int>());
	
	for(int j = 1; j <= m; j++)
	{
		if(j % 2)
		{
			for(int i = 1; i <= n; i++)
			{
				operate(i, j);
			}
		}
		else
		{
			for(int i = n; i > 0; i--)
			{
				operate(i, j);
			}
		}
	}
	
	return 0;
}

