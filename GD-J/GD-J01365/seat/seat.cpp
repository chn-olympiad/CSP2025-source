#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[121],c,s,k;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> b[i];
	}
	c = b[1];
	sort(b+1,b+1+n*m);
	for(int i = 1;i <= n*m;i++)
	{
		if(b[i] == c)
		{
			s = n*m-i;
			break;
		}
	}
	int x = s/n,y = s%n;
	if(x%2 == 1)
	{
	    if(y > 0)
	    {
	    	x++;
	    	k = n-y+1;
		}
		if(y == 0)
		{
			x++;
			k = n;
		}
	}
	else
	{
		if(y == 0)
		{
			x++;
			k = 1;
		}
		if(y > 0)
		{
			x++;
			k = n-y+1;
		}
	}
	cout << x << " " << k;
	return 0;
}
