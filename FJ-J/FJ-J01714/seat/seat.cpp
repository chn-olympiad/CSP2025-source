#include <bits/stdc++.h>
using namespace std;

struct X
{
	int x, id;
}a[105];

bool cmp(X x, X y)
{
	return x.x > y.x; 
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int cur = 0;
	for(int i = 1; i <= m; i++)
	{
		if(i % 2 == 0)
		{
			for(int j = n; j >= 1; j--)
			{
				cur++;
				if(a[cur].id == 1)
				{
					cout << i << " " << j;
					return 0;		
				}		
			}			
		}
		else 
		{
			for(int j = 1; j <= n; j++)
			{
				cur++;
				if(a[cur].id == 1)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
