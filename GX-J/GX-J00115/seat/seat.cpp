#include<bits/stdc++.h>
using namespace std;
int c[15][15];
int j=0;
int x1,x2;
int b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>b[i];
	}
	int x=b[0];
	for(int i=0;i<n*m-1;i++)
	{
		for(int k=i;k<n*m;k++)
		{
			if(b[k]>b[i])
			{
				swap(b[k],b[i]);
			}
		}
	}
	for(int i=0;i<n*m;i++)
	{
		if(x==b[i])
		{
			x1=i+1;
		}
	}
	x2=ceil(1.0*x1/n);
	if(x2%2==0)
	{
		cout<<x2<<" "<<x2*n-x1+1;
	}
	else
	{
		if(x1%n==0)
		{
			cout<<x2<<" "<<n;
		}
		else
		{
			cout<<x2<<" "<<x1%n;
		}
	}
	return 0;
}
