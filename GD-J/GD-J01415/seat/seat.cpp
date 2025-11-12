#include<bits/stdc++.h>
//#define ll long long
using namespace std;
long long a[15][15];
long long b[105];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	long long x=b[1];
	long long c=1;
	sort(b+1,b+n*m+1,cmp);
	for(long long i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[j][i]=b[c];
				c++;
			}
		}
		else
		{
			for(long long j=n;j>=1;j--)
			{
				a[j][i]=b[c];
				c++; 
			}
		}
	}
//	for(long long i=1;i<=n;i++)
//	{
//		for(long long j=1;j<=m;j++)
//		{
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(a[i][j]==x)
			{
				cout<<j<<" "<<i<<" ";
				return 0;
			}
		}
	}
	return 0;
 } 
