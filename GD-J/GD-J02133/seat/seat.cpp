#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],s,x,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=m*n;
	for(int i=1;i<=s;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	for(int i=s;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j+1],a[j]);
			}
		}
	}
	for(int i=1;i<=s;i++)
	{
		if(a[i]==x)
		{
			x=i;
			break;
		}
	}
	c=x/n;
	if(x%n!=0)
	{
		c+=1;
	}
	r=x%n;
	if(x%n==0)
	{
		r=n;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
