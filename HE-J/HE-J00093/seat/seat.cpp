#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l;
	cin>>h>>l;
	int f;
	cin>>f;
	int n=1;
	for(int i=1;i<=h*l-1;i++)
	{
		int z;
		cin>>z;
		if(z>f){
			n++;
		}
	}
	int s=n/l;
	int y=n%l;
	int zl;
	if(y==0)
	{
		zl=s;
	}
	else
	{
		zl=s+1;
	}
	int zh;
	if(zl%2!=0)
	{
		zh=n-(zl-1)*h;
	}
	else
	{
		zh=zl*h+1-n;
	}
	cout<<zl<<' '<<zh;
	return 0;
 } 
