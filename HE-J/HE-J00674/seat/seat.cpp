#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c,d;
	cin>>m>>n;
	int a[n][m],b[m*n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;i<m;i++)
	{
		cin>>b[j];
	}
	}
	c=b[1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(b[j]>b[j+1])
			{
				d=b[j+1];
				b[j+1]=b[j];
				b[j]=d;	
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(b[j]==c)
			{
				cout<<b[j];
			}
		}
	}
}
