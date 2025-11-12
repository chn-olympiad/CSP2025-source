#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105][105],b[10005],s;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>b[i];
		if(i==1)
		s=b[i];
	}
	sort(b+1,b+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++)
	{
		long long x,y;
		if(i%n==0)
		x=i/n;
		else
		x=i/n+1;
		y=i-n*(x-1);
		if(x%2==1)
		{
			y=y;
		}
		else
		{
			y=n-y+1;
		}
		a[x][y]=b[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(a[i][j]==s)
			cout<<i<<' '<<j<<endl;
		}
	}
	return 0;
}
