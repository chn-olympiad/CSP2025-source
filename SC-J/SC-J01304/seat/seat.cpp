#include<bits/stdc++.h>
using namespace std;
int a,b,c,d=1,e;
int x[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i=i+1)
	{
		cin>>x[i];
	}
	c=x[1];
	for(int i=1;i<=a*b;i=i+1)
	{
		if(x[i]>c)
		{
			d=d+1;
		}
	}
	e=d/a;
	d=d%a;
	if(e%2==0)
	{
		if(d==0)
		{
			cout<<e<<" 1";
		}
		else
		{
			cout<<e+1<<" "<<d;
		}
	}
	if(e%2==1)
	{
		if(d==0)
		{
			cout<<e<<" "<<a;
		}
		else
		{
			cout<<e+1<<" "<<a-d+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}