#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[105],t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=1;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=n*m;j>i;j--)
		{
			if(a[j]>a[j-1])
			{
				if(t==j)
					t=j-1;
				if(t==j-1)
					t=j;
				swap(a[j],a[j-1]);
			}
		}
	} 
	int c,r;
	if(t%n==0)
		c=t/n;
	else
		c=t/n+1;
	if(c%2==1)
		r=t-(c-1)*n;
	else
		r=n-(t-(c-1)*n)+1;
	cout<<c<<" "<<r;
	return 0;
 } 