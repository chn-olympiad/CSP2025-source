#include <bits/stdc++.h>
using namespace std;
int m,n,i;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[100];
	int a1,c,r,l=0;
	cin>>n>>m;
	for(i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(i==0)
		{
			a1=a[i];
		}
	}
	sort(a,a+(m*n));
	for(i=n*m;i>=0;i--)
	{
		if(a1==a[i])
		{
			break;
		}
		l++; 
	}
	
	c=l/n+1;
	if(l%n==0)
	{
		r=n;
	}
	else
	{
		r=l%n;
	}
	if((l/m+1)%2==0)
	{
		r=n-r+1;
	}
cout<<c<<" "<<r;
	return 0;
}