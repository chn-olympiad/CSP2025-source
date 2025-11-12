#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,k;
int a[10000];
int main()
{
	freeopen("seat.in","r",stdin);
	freeopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	c=1;
	r=1;
	k=a[1];
	if(n==1&&m==1)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	if(n==1)
	{
		r=1;
		sort(a+1,a+1+n*m);
		for(int i=m;i>=1;i--)
		{
			
			if(a[i]==k)
			{
				cout<<1<<" "<<r;
			}
			r++;
		}
	}
	if(m==1)
	{
		c=1;
		sort(a+1,a+1+n*m);
		for(int i=n;i>=1;i--)
		{
			
			if(a[i]==k)
			{
				cout<<c<<" "<<r;
			}
			c++;
		}
	}	
	return 0;
}











