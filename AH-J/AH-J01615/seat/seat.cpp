#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int a1=a[0];
	for(int i=0;i<n*m;i++)
	{
		if(a[i]<a[i+1])
		{
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(i%2!=0)
		{
			for(int j=n-1;j>n;j--)
			{
				if(a[(i+1)*n-j-1]==a1)
				{
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
		else
		{
			for(int j=0;j<n;j++)
			{
				if(a[i*n+j]==a1)
				{
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
	}
}
