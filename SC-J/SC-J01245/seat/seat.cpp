#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,x=0,y=0,xy=0;
	cin>>a>>b;
	int t=a*b;
	int tmp,r;
	cin>>r;
	for(int i=1;i<t;i++)
	{
		cin>>tmp;
		if(tmp>r)
		{
			xy++;
		}	
	}
	xy++;
	x=xy/a+1;
	if(xy%a==0)
	{
		x--;
	}
	if(x%2==0)
	{
		y=a-xy%a+1;
	}
	else
	{
		y=xy%a;
		
	}
	if(xy%a==0)
	{
		y=a;
		if(x%2==0)
		{
			y=1;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}