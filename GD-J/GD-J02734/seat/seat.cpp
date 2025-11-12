#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int n , m , a [N] , k;
int b [110] [110];
bool cmp (int b1 , int b2)
{
	return b1 > b2;
}
signed main()
{
		freopen ("seat.in" , "r" , stdin);
		freopen ("seat.out" , "w" , stdout);
		cin >> n >> m;
		int x = n * m;
		for (int i = 1; i <= x; i++)
			scanf ("%lld" , &a [i]);
		int y = a [1];
		sort (a + 1 , a + x + 1 , cmp);
		for (int i = 1; i <= x; i++)
		{
			if (a [i] == y)
			{
				y = i;
				break;
			} 
		}
		for (int i = 1; i <= m; i++)
		{
			if (i & 1)
			{
				for (int j = 1; j <= n; j++)
				{
					b [i] [j] = a [++k];
					if (k == y)
					{
						cout << i << " " << j;
						return 0;
					}
				}
			}			
			else
			{
				for (int j = n; j >= 1; j--)
				{
					b [i] [j] = a [++k];
					if (k == y)
					{
						cout << i << " " << j;
						return 0;
					}
				}
			} 		
		}	
		return 0;
}

