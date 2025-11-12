#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005],m,n,s,r,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	s=m*n;
	for(int i=1;i<=s;i++)
	{
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+s+1);
	for(int i=1;i<=s;i++)
	{
		if(a[i]==r)
		{
			r=s-i+1;
			y=r/n+1;
			x=r%n;
			if(x==0)
			{
				x=n;
				y--;
			}
			if(y%2==0)
			{
				x=n-x+1;
			}
			cout<<y<<" "<<x;
		}
	}
	return 0;
}
