#include<bits/stdc++.h>
using namespace std;
int main()
{
	int b,a3,a2,a1[101],n,m,c,r,xr;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a1[i];
	}
	xr=a1[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m-1;j++)
		{
			a2=max(a1[j],a1[j+1]);
			a3=min(a1[j],a1[j+1]);
			a1[j]=a2;a1[j+1]=a3;
		}
	} 
	for(int i=1;i<=n*m;i++)
	{
		if(a1[i]==xr)
		{
			b=i;
			break;
		}		
	}
	if(b%n==0)
	{
		c=b/n;
		if(c%2==0)
		{
			r=1;
		}
		else
		{
			r=n;
		}
	}
	if(b%n!=0)
	{
		c=b/n+1;
		if(c%2==0)
		{
			r=n+1-b%n;
		}
		else
		{
			r=b%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
