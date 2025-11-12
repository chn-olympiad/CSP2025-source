#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,a=0,d=0,x=0,y=0;
	cin>>n>>m;
	a=n*m;
	int b[a+2];
	for(int i=0;i<a;i++)
	{
		cin>>b[i];
	}
	int c=b[0];
	for(int i=a;i>=1;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(b[j]<b[j+1])
			{
				swap(b[j],b[j+1]);
			}
		}
	}
	for(int i=0;i<105;i++)
	{
		if(b[i]==c)
		{
			d=i+1;
			break;
		}
	}
	if(d%n==0)
	{
		x=d/n;
	}
	if(d%n!=0)
	{
		x=d/n+1;
	}
	if(x%2==1)
	{
		if(d==n){
			y=n;
		}
		if(d!=n){
			y=d%n;
		}
	}
	if(x%2==0)
	{
		y=n*x-d+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
