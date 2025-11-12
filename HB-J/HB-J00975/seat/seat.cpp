#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],x,b=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	for(int i=1;i<=m*n;i++)
	{
		for(int j=i;j<=m*n;j++)
		{
			if(a[i]<a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			b=i;
			break;
		}
	}
	int c=b/m;
	if(b%m==0)
	{
		if(c%2==0)
		{
			cout<<c<<" 1";
		}
		else 
		{
			cout<<c<<" "<<n;
		}
	}
	else
	{
		c++;
		if(c%2==0)
		{
			cout<<c<<" "<<n;
		}
		else 
		{
			cout<<c<<" 1";
		}
	}
	return 0;
}
