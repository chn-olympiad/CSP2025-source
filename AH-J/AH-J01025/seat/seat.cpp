#include<bits/stdc++.h>
using namespace std;
int a[101],b[101][101];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,n,m,k=1,s;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(j=1;j<=n;j++)
			{
				b[i][j]=a[k];
				k++;
			}
		}
		else
		{
			for(j=n;j>=1;j--)
			{
				b[i][j]=a[k];
				k++;
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(s==b[i][j])
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
