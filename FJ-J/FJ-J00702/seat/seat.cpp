#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,x,y;
int a[101];
bool xy(int w,int v)
{
	return w>v;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	} 
	x=a[0];
	sort(a,a+n*m,xy);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==x)
		{
			y=i+1;
		}
	}
	c=y/n;
	if(y%n==0&&c%2==1)
	{
		r=n;
		cout<<c<<" "<<r;
	}
	else if(y%n==0&&c%2==0)
	{
		r=1;
		cout<<c<<" "<<r;
	}
	else if(c%2==0)
	{
		r=y%n;
		cout<<c+1<<" "<<r;
	}
	else if(c%2==1)
	{
		r=n-y%n+1;
		cout<<c+1<<" "<<r;
	}
	
	return 0;
}
