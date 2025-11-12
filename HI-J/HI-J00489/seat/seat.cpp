#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m  , r , rg;
	cin >> n >> m ;
	int a[245] = {};
	for (int i = 1 ; i <= n*m ; ++i )
	{
		cin >> r;
		a[i] = r;
	}
	rg = a[1] , r = 1;
	for (int i = 1 ; i <= m*n ; ++i)
	{
		if (a[i] > rg)
		{
			r += 1;
		}
	}
	
	int width = 1 , height = 1 , ans = 1;
	bool limit = 1;
	for (int i = 1 ; i <= n*m ; ++i)
	{
		if (ans == r)
		{
			cout << width << " " << height;
			return 0;
		}
		
		if (limit == 1)
		{
			height++;
			ans++;
			if (ans == r)
			{
				cout << width << " " << height;
				return 0;
			}
			else if(height+1 > m)
			{
				width++;
				ans++;
				limit = 0;
				if (ans == r)
				{
					cout << width << " " << height;
					return 0;
				}
			}
		}
		else if (limit == 0)
		{
			height--;
			ans++;
			if (ans == r)
			{
				cout << width << " " << height;
				return 0;
			}
			else if (height-1 < 1)
			{
				width++;
				ans++;
				limit = 1;
				if (ans == r)
				{
					cout << width << " " << height;
					return 0;
				}
			}
		}
		
	} 
	return 0;
}
