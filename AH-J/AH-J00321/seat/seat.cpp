#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int z[10005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int af;
	for(int i=1;i<=m*n;i++)
	{
		cin>>z[i];
	}
	af=z[1];
	sort(z+1,z+m*n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int sum=(i-1)*n+j;
			a[i][j]=z[sum];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==af)
			{
				if(i%2==1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				else
				{
					cout<<i<<" "<<1+n-j;
					return 0;
				}
			}
		}
	}
	return 0;
}
