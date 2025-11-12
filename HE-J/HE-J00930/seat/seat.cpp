#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
    long long p;
	cin >> n >> m;
	long long b[n * m + 10];
	for(int i = 1;i <= n * m;i ++) cin >> b[i];
	long long v = b[1];
	sort(b + 1,b + n * m + 1);
	int x = 1,y = 0;
	int z[n + 10][m + 10];
	for(int i = n * m;i >= 1;)
	{
		if(x % 2 != 0 && y != n)
		{
			y ++;
			z[x][y] = b[i];
			i --;
		}
		if(x % 2 != 0 && y == n)
		{
			x ++;
			z[x][y] = b[i];
			i --;
	    }
	    if(x % 2 == 0 && y != 1)
	    {
	    	y --;
	    	z[x][y] = b[i];
	    	i --;
		}
		if(x % 2 == 0 && y == 1)
		{
			x ++;
			z[x][y] = b[i];
			i --;
		}
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
		    if(z[i][j] == v)
		    {
		    	cout << i << " " << j;
		    	return 0;
			}
		}
	}
	return 0;
}
