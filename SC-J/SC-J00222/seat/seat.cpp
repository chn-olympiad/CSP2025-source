#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a [N] , b [N] [N];
 
int main ()
{
	freopen ("seat.in" , "r" , stdin);
	freopen ("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	int cur = 0;
	for (int i = 1;i <= m * n;i++)
	{
		cin >> a [i];	
	}
	int x = a [1];
	sort (a + 1 , a + n * m + 1 , greater <int> ());
	for (int i = 1;i <= m;i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1;j <= n;j++)
			{
				b [j] [i] = a [++ cur];
			}
		}
		else
		{
			for (int j = n;j >= 1;j--)
			{
				b [j] [i] = a [++ cur];
			} 
		}
	}
	int c , r;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (b [i] [j] == x)
			{
				c = i;
				r = j;
			} 
		}
	}
	cout << r << " " << c;
	return 0;
} 
