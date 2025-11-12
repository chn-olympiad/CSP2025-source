#include<bits/stdc++.h>
using namespace std;
int a[102],sum,b[12][12];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1);
	int k=n*m;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				b[i][j]=a[k];
				k--;
			}
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				b[i][j]=a[k];
				k--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==sum)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
} 
