#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e1 + 5;

int cnt, m, n, a[MAXN * MAXN];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			cin >> a[++ cnt];
		}
	}
	
	int tar = a[1];
	
	sort(a + 1, a + cnt, cmp);
	
	int ans = 0; bool flag = false;
	
	for (int i = 1; i <= m; i ++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j ++)
			{
				ans ++;
				
				if (a[ans] == tar)
				{
					cout << i << " " << j; return 0;
				}
			}
		}
		else
		{
			for (int j = n; j >= 1; j --)
			{
				ans ++;
				
				if (a[ans] == tar)
				{
					cout << i << " " << j; return 0;
				} 
			}
		}
		
		if (flag == true) break;
	}
	
	cout << ans;
	
	return 0;
}
