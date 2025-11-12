#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[10000],max=-1,x[10000];
	cin>>n>>m;
	int a[n][m],b[n][m];
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		if(s[i]>max)
		{
			max=s[i];
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=b[i][j];
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				a[i][j]=x[];
			}
		}
	}
	cout<<i<<" "<<j;
	return 0;
}
