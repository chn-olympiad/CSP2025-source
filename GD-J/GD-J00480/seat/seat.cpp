#include <bits/stdc++.h>
using namespace std;
int n,m;
//int k [12][12];
int a [144];
bool cmp (int x,int y)
{
	return x > y;
}
int main ()
{
    freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a [1];
	int R = a [1];
	for (int i = 2;i <= n * m;i ++)
	{
		cin >> a [i];
	}
	sort (a + 1,a + n * m + 1,cmp);
	int k = 0;
	for (int i = 1;i <= n * m;i ++)
	{
		if (a [i] == R)
		{
			k = i;
			break;
		}
	}
    int x =  1 + k / (n + 1);
    int y = k % n;
    if (x % 2 == 0)
    {
    	if (y == 0)
    	{
    		y = 1;
		}
		else
		{
			y = n + 1 - y;
		}
	}
	else
	{
		if (y == 0)
    	{
    		y = n;
		}
	}
	cout << x << ' ' << y;
	return 0;
}
