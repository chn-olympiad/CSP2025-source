#include<bits/stdc++.h>
using namespace std;
long long n,m,a[15][15],f[110],r,b[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>f[i];
	}
	r=f[1];
	sort(f+1,f+n*m+1,greater<int>());
	for(long long i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			
			b[i][j]=f[n*(j-1)+i];
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(j%2==0)
			{
				a[i][j]=b[1+n-i][j];
			}
			else
			{
				a[i][j]=b[i][j];
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(a[i][j]==r)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
