#include<bits/stdc++.h>
using namespace std;
long long n,m,r,sum=1,x,y;
long long a[20][20];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	r=a[1][1];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]>r)
			{
				sum++;
			}
		}
	}
	x=sum/m+1;
	y=sum-(sum/m*m);
	cout<<x<<" "<<y;
	return 0;
} 
