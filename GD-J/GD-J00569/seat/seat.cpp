#include<bits/stdc++.h>

using namespace std;
long long n,m,a[105],k,p,x[15][15],l=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(long long j=1;j<=m;j++)
			{
				x[j][i]=a[l++];
			}
		}
		else
		{
			for(long long j=m;j>=1;j--)
			{
				x[j][i]=a[l++];
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(x[j][i]==k) printf("%lld %lld",i,j);
		}
	}
	
	
	return 0;
 }
