#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e03 + 7;

int n, m;

int a[MAXN];

int s[17][17];

bool cmp(int a, int b)
{
	return a > b;
}

signed main() 
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
		
	int lst = a[1];
	
	sort(a + 1, a + n * m + 1, cmp);
	
	int rk = 0;
	
	for(int i = 1; i <= m * n; i++)
	{
		if(a[i] == lst)
		{
			rk = i;
			break;
		}
	}
	
	int x = 1, y = 1, now = 1, whc = 0;
	
	while(1)
	{
		s[x][y] = now;
		++now;
		if(!whc)
		{
			if(x == n)
			{
				whc ^= 1;
				++y;
			}
			else if(x < n)
				++x;
		}
		else
		{
			if(x == 1)
				whc ^= 1, ++y;
			else
				--x;
		}
		if(now == n * m + 1)
			break;
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s[i][j] == rk)
			{
				printf("%d %d", j, i);
				return 0;
			}
		}
	}
	
	return 0;
}
