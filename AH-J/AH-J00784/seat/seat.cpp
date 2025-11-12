#include <iostream>
#include <cstdio> 
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int a[105];
int b;
int x,y;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> a[i];
	}
	b = a[1];
	sort(a+1,a+n*m+1,greater<>());
	for (int i = 1; i <= n*m; i++)
	{
		if (b == a[i])
		{
			b = i;
			break;
		}
	}
	x = b/n;
	y = b%n;
	if (x % 2 == 1)
	{
		y = n - y + 1;
		if (y == n+1)
		{
			y--;
		}
		else 
		{
			x++;
		}
	}
	else 
	{
		if (y == 0)
		{
			y++;
		}
		else 
		{
			x++;
		}
	}
	cout << x << " " << y;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
