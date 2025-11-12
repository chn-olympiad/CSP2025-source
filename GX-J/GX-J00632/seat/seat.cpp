#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,x,y,r;
int a[1010];
bool cmp1(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			x=i;
		}
	}
	int t=x;
	if(t%n!=0)
	{
		y=t/n+1;
	}
	else
	{
		y=t/n;
	}
	if(y%2==1)
	{
		x-=(y-1)*n;
	}
	else
	{
		x-=(y-1)*n;
		x=n-x+1;
	}
	cout<<y<<" "<<x;
	return 0;
}

