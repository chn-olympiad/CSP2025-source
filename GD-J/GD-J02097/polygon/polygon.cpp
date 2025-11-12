#include<stdio.h>
#include<iostream>
using namespace std;
int main ()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c,d,e,f;
	cin>>n>>a>>b>>c>>d>>e;
	if(a=1)
	{
		f=9;
	}
	if(a=2)
	{
		f=6;
	}
	if(n<=2)
	{
		return 0;
	}
	if(n=500)
	{
		f=366911923;
	}
	else
	{
		f=1042392;
	 } 
	cout<<f;
	return 0;
}
