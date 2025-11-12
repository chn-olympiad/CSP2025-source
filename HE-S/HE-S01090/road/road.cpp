#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >>m >>k;
	bool zero=true,zero1=true;
	long long link[m+1][4];
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=3;j++)
		{
			cin >>link[i][j];
			if (j==3&&link[i][j]!=0)
			{
				zero=false;
			}
		}
	}
	int c[k+1][6];
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=5;j++)
		{
			cin >>c[i][j];
			if (j!=1&&c[i][j]!=0)
			{
				zero1=false;
			}
		}
	}
	if (zero||zero1)
	{
		cout <<0;
		return 0;
	}
	return 0;
}
