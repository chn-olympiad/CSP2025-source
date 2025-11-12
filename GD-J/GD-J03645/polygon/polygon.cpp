#include<bits/stdc++.h>
using namespace std;
int n,x[5005][5005],y[5005];
int i,j,num;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.ont","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>j;
		y[i]=y[i-1]+j;
		x[i][i]=j;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(x[j][j]<x[i][j-1])
			{
				x[i][j]=x[i][j-1];
			}
			else
			{
				x[i][j]=x[j][j];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+2;j<=n;j++)
		{
			if(x[i][j]*2<y[j]-y[i])
			num++;
		}
	}
	cout<<num<<endl;
	return 0;
}
