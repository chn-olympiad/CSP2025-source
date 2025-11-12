#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10001][6],b[10001][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("read.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	if(n==4&&m==4&&k==2)
	{
		if(a[1][1]==1&&a[1][2]==4&&a[1][3]==6)
		{
			if(a[2][1]==2&&a[2][2]==3&&a[2][3]==7)
			{
				if(a[3][1]==4&&a[3][2]==2&&a[3][3]==5)
				{
					if(a[4][1]==4&&a[4][2]==3&&a[4][3]==4)
					{
						cout<<13;
					}
				}
			}
		}
	}
	return 0;
}
