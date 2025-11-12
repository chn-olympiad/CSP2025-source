#include<bits/stdc++.h>
using namespace std;
long long a[105];
bool cmp(long long a,long long b)
{
	return a>b; 
 } 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,c=1;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int l=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++)
	{
		if(l==a[i])
		{
			l=i;
			break;
		 } 
	}
	for(long long j=1;j<=m;j++)
	{
		if(j%2==0)
		{
			for(long long i=n;i>=1;i--,c++)
			{
				if(c==l)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else
		{
			for(long long i=1;i<=n;i++,c++)
			{
				if(c==l)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
}
