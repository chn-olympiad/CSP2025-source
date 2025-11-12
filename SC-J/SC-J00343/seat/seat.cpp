#include<bits/stdc++.h>
using namespace std;
int m,n,a[120],b[120],c;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b[i]=i;
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[i]>a[j])
			{
				c=a[i];
				a[i]=a[j];
				a[j]=c;
				c=b[i];
				b[i]=b[j];
				b[j]=c;				
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==1)
		{
			c=i;
			break;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if((c-n)>0)
			c-=n;
		else
		{
			if(i%2!=0)
				cout<<i<<" "<<c;
			else
				cout<<i<<" "<<n-c+1;
			break;
		}
	}
	return 0;
}