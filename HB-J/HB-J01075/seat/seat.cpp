#include<bits/stdc++.h>
using namespace std;
int m,n,a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int c(int x,int y)
{
	for(int i=1;;i++)
	{
		if(x<y)
		{
			return i-1;
		}
		x-=y;
	}
}
int d(int x,int y)
{
	return x-c(x,y)*y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int h=m*n;
	for(int i=1;i<=h;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+h+1,cmp);
	int g=0;
	for(int i=1;i<=h;i++)
	{
		if(a[i]==t)
		{
			g=i;
		}
	}
	int ansx=c(g,n);
	if(d(g,n)>0)
	{
		ansx++;
	}
	int ansy=0;
	if(d(ansx,2)==0)
	{
		ansy=(n-d(g,n))+1;
		if(d(g,n)==0)
		{
			ansy=1;
		}
	}
	else
	{
		ansy=d(g,n);
		if(d(g,n)==0)
		{
			ansy=n;
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}

 
