#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	int a[15][15];
	bool way = false;
	int b[105];
	
	cin >> n >> m;
	for(int i = 1; i<=n*m; i++)
	{
		cin >> b[i];
	 } 
	int num = b[1],now = 0,i = 1;
	sort(b+1,b+n*m+1,cmp);
	int x = 1, y = 1;
	while(i <= n*m)
	{
		a[x][y] = b[i];
		if(a[x][y] == num)
		{
			cout << y << " " << x;
			return 0;
		}
		if(way)
		{
			if(x-1>=1) 
			{
				x--;
				i++;
			}
			else
			{
				y++;
				i++;
				way = false;
			}
		 } 
		else
		{
			if(x+1 <= n)
			{
				x++;
				i++;
			}
			else
			{
				y++;
				i++;
				way = true;
			}
		}
	}
	 
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
