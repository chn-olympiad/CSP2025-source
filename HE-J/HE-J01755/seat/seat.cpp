#include<bits/stdc++.h>
using namespace std;
int num[114514],a[114514][114514],R;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,m,n,l;
	int sum[114514];
	cin>>x>>y;
	n=x*y;
	for(int i=1;i<=n;i++)
	{
		cin>>sum[i];
	}
	R=sum[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(sum[i]>=sum[j]&&sum[i]>=m)
			{
				m=sum[i];
			}
			else if(sum[i]<sum[j]&&sum[j]>=m)
			{
				m=sum[j];
			}
		}
		num[i]=m;
		for(int k=1;k<=n+1;k++)
		{
			if(sum[k]==m)
			{
				sum[k]=-1;
				break;
			}
		}
		m=0;
	}
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			y++;
			a[i][j]=num[l];
			if(a[i][j]==R)
			{
				cout<<i<<j;
			}
		}
	}
	return 0;
}
