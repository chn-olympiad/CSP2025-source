#include<bits/stdc++.h>
using namespace std;
int a[1000];
int b[20][20];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	a1=a[0];
	sort(a,a+n*m);
	int c=0;
	for(int i=n;i>0;i--)
	{
		if(i%2==1)
		{
			for(int j=m;j>0;j--)
			{
				b[i][j]=a[c];
				c++;
			}
		}else
		{
			for(int j=1;j<=m;j++)
			{
				b[i][j]=a[c];
				c++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==a1)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
