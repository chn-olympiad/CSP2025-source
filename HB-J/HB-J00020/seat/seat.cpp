#include<bits/stdc++.h>
using namespace std;
int n,m,r,d=0;
int main()
{
	cin>>n>>m;
	int a[n*m]={};
	for(int i=0;i<=n*m-1;i++)
	{
		cin>>a[i];
	}
	r=a[0];
	for(int i=0;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m-1;j++)
		{
			if(a[i]<a[j])
			{
				int y=a[i];
				a[i]=a[j];
				a[j]=y;
			}
		}
	}
	int b[n][m]={};
	for(int i=0;i<=m-1;i++)
	{
		if(i%2==1)
		{
			for(int j=0;j<=n-1;j++)
			{
				b[j][i]=a[d];
				d++;
				if(b[j][i]==r)
				{
					cout<<j<<' '<<i;
					break;
				}
			}
		}
		if(i%2==0)
		{
			for(int j=n-1;j>=0;j++)
			{
				b[j][i]=a[d];
				d++;
				if(b[j][i]==r)
				{
					cout<<j<<' '<<i;
					break;
				}
			}
		}
	}
	return 0;
}
