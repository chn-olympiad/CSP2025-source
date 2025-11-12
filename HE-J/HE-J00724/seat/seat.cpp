#include<bits/stdc++.h>
using namespace std;
int a[1086];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int lgl=n*m;
	for(int i=0;i<lgl;i++)
	{
		cin>>a[i];
	}
	int aaa=a[0];
	int pm=1;
	for(int i=1;i<lgl;i++)
	{
		if(a[i]>aaa)pm++;
	}
	int c=0,r=0;
	if(pm%n==0)
	{
		c=pm/n;
		if(c%2==0)
		{
			r=1;
		}
		else
		{
			r=n;
		}
	}
	else
	{
		c=pm/n+1;
		if(c%2==0)
		{
			r=n-(pm%n)+1;
		}
		else
		{
			r=pm%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
