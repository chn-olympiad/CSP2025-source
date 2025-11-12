#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+2];
	int z;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[(i-1)*m+j];
			if(i==1&&j==1)
			{
				z=a[(i-1)*m+j];
			}
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[(i-1)*m+j]==z)
			{
				if(i%2==0)
				{
					cout<<i<<" "<<(m-j+1);
				}
				else
				{
					cout<<i<<" "<<j;
				}
			}
		}
	}
	return 0;
}
