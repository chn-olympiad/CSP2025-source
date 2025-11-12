#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000],p,k;
int c,r,f;
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{	int t;
		cin>>t;
		a[i]=-1*t;
	}
	p=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			k=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{	
			for(int j=1;j<=n;j++)
			{
				f++;
				if(f==k)
				{
					c=i;
					r=j;
				}
			}
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				f++;
				if(f==k)
				{
					c=i;
					r=j;
				}
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
