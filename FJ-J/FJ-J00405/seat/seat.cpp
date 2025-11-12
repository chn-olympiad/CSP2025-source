#include<bits/stdc++.h>
using namespace std;
long long a[105];
long long c[105][105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	long long s=a[1];
	sort(a+1,a+n*m+1);
	long long ans=n*m;
	for(long long i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(long long j=1;j<=n;j++)
			{
				c[j][i]=a[ans];
				ans--;
				if(c[j][i]==s)
				{
					cout<<i<<' '<<j;
					continue;
				}
			}
		}
		else
		{
			for(long long j=n;j>=1;j--)
			{
				c[j][i]=a[ans];
				ans--;
				if(c[j][i]==s)
				{
					cout<<i<<' '<<j;
					continue;
				}
			}
		}
	}
	return 0;
}
