#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
int a[201], mp[201][201];

bool cmp(int x, int y)
{
	return x > y;
}

void then()
{
	if (x == 0 && y == 0)
	{
		x = 1;
		y = 1;
	}
    else if (x % 2 == 1 && y == n)
	{
		x ++;
	}
	else if (x % 2 == 0 && y == 1)
	{
		x ++;
	}
	else if (x % 2 == 1)
	{
		y ++;
	}
	else
	{
		y --;
	}
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int flag;
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
		if (i == 1) flag = a[i];
	}
	
	sort(a + 1, a + n * m + 1, cmp);
	
	bool f = 1;
	for (int i = 1; i <= n * m; i++)
	{
		then();
		
		if (a[i] == flag)
		{
			cout << x << " " << y << endl; 
			break;
		}
	}
	
	return 0;
}
