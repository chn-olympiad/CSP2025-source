#include <bits/stdc++.h>
using namespace std;
cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
			cin>>a[i];
	}
	int b=a[1];
	int c[11][11];
	long long top=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int num=0;
			num=ceil(top*1.0/n);
			top++;
			if(num%2==0)
			{
				c[i][j]=a[i*n-j+1];
			}
			else
			{
				c[i][j]=a[(i-1)*n+j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]==b)
			{
			cout<<i<<" "<<j;
	}
	}
	}
	return 0;
}
