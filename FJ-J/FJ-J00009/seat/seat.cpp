#include<bits/stdc++.h>
using namespace std;
long long b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a,c,d,x,y,e=0;
	cin>>n>>m;
	a=n*m;
	for(long long i=1;i<=a;i++)
	{
		cin>>b[i];
	}
	c=b[1];
	sort(b+1,b+1+a);
	for(long long i=a;i>=1;i--)
	{
		e++;
		if(b[i]==c)
		{
			d=e;
		}
	}
	if(d%n==0)
	{
		x=d/n;
	}
	else
	{
		x=d/n+1;
	}
	if(x%2==1)
	{
		if(d%n==0)
		{
			y=n;
		}
		else
		{
			y=d%n;
		}		
	}
	else
	{
		if(d%n==0)
		{
			y=n+1-n;
		}
		else
		{
			y=n+1-d%n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
