#include<bits/stdc++.h>
using namespace std;
int n,m,a[200]={0},xr,r;
bool cmp(int x,int y)
{
	return x>y;
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
	xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xr)
		{
			r=i;
			break;
		}
	}
	int x,y=ceil(r*1.0/n);
	if(y%2==1)
	{
		if(r%n==0)
		{
			x=n;
		}
		else
		{
			x=r%n;
		}
	}
	else
	{
		if(r%n==0)
		{
			x=1;
		}
		else
		{
			x=n-(r%n)+1;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
