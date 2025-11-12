#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],t,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	t=a[0];
	sort(a,a+n*m,greater<int>());
	x=1;
	y=1;
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==t)
		{
			cout<<y<<" "<<x;
			return 0;
		}
		if(y&1)
		{
			if(x+1<=n)
			{
				x++;
			}
			else
			{
				y++;
			}
		}
		else
		{
			if(x-1>=1)
			{
				x--;
			}
			else
			{
				y++;
			}
		}
	}
	return 0;
}
