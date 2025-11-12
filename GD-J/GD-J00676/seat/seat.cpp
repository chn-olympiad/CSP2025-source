#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[150],x=0;
	cin>>n>>m;
for(int i=1;i<=n*m;i++)
{
	cin>>a[i];
}
for(int i=1;i<=n*m;i++)
{
	if(a[i]>a[1])
	{
		x+=1;
	}
}
int xz=0;
for(int i=1;i<=n;i++)
{
	int c,r;
	if(i%2!=0)
	{
		c=i;r=1;
		for(int j=1;j<=m;j++)
		{
			if(xz==x)
			{
				cout<<c<<" "<<r;return 0;
			}	
			r+=1;
			xz+=1;
		}
	}
	else
	{
		c=i;r=i;
		for(int j=1;j<=m;j++)
		{
			if(xz==x)
			{
				cout<<c<<" "<<r;return 0;
			}
			r-=1;
			xz+=1;
		}
	}
}
}
