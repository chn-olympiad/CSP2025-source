#include<bits/stdc++.h>
using namespace std;

int n,m,a[114],zw[15][15],t,r,zrs;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	zrs=n*m;
	for(int i=1;i<=zrs;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+zrs+1,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2!=0)
		{
			for(int i=1;i<=n;i++)
			{
				t++;
				zw[i][j]=a[t];
			}
		}
		if(j%2==0)
		{
			for(int i=n;i>=1;i--)
			{
				t++;
				zw[i][j]=a[t];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(zw[i][j]==r)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
