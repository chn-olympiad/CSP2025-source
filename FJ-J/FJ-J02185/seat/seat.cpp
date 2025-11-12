#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	long x,y,z,x_1,y_1=0;
	scanf("%d%d",&x,&y);
	z=x*y;
	const long x_2=x,y_2=y;
	long s[x_2][y_2],g,p=1,a;
	cin>>g;
	for(long i=1;i<z;++i)
	{
		cin>>a;
		if(a>g)
			++p;
	}
	if(p%x!=0)
	{
		++y_1;
	}
	y_1+=p/x;
	if(y_1%2==0)
	{
		x_1=x+1;
		x_1-=p%x;
	}
	else
	{
		x_1=0;
		x_1+=p%x;
		if(x_1==0)
			x_1=x;
	}
	printf("%d %d",y_1,x_1);
	
	return 0;
}
