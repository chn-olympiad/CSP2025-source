#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q=0,c;
	int x,y;
	cin >>n>>m;
	int a[111];
	memset(a,0,sizeof(a));
	for(int i=1;i<=n*m;i++) cin >>a[i];
	c=a[1];
	for(int y=1;y<=n*m;y++)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(a[i]<a[i+1])
			{
				q=a[i];
				a[i]=a[i+1];
				a[i+1]=q;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==c)
		{
			c=i;
			break;
		}
	}
	if(c%n==0) x=c/n;
	else
	x=c/n+1;
	if(x%2==1)
	{
		if(c%n==0) y=n;
		else
		y=c%n;
	}
	if(x%2==0)
	{
		if(c%n==0) y=1;
		else
		y=n+1-c%n;
	}
	cout<<x<<" "<<y;
	return 0;
}
