#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[105],c=0,d=0;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	c=b[1];
	for (int i=1;i<=n*m;i++)
	{
		for (int k=1;k<=n*m-i;k++)
		{
			if (b[k]<b[k+1])
			{
				d=b[k];
				b[k]=b[k+1];
				b[k+1]=d;
				d=0;
			}
		}
	}
	for (int i=1;i<=n*m;i++)
	{
		if (c==b[i])
		{
			int q=i/m;
			if (q%2==1 && i%m!=0)
			{
				cout<<q+1<<" "<<m-i%m+1;
			}
			if (q%2==1 && i%m==0)
			{
				cout<<q<<" "<<m;
			}
			if (q%2==0 && i%m!=0)
			{
				cout<<q+1<<" "<<i-q*m;
			}
			if (q%2==0 && i%m==0)
			{
				cout<<q<<" "<<1;
			}
		}
	}
	return 0;
}
