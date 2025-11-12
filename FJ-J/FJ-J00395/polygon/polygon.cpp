#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5010];
long long b[5010];
long long ans=0;
void d(long long x,long long y,long long z)
{
	if(x<0&&z>=3)
	{
		ans+=b[y-1]+1;
		ans=ans%998244353;
		return;
	}
	if(y==1)
	{
		return;
	}
	for(long long i=y-1;i>=1;i--)
	{
		d(x-a[i],i,z+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	b[0]=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]*2+1;
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=3;i--)
	{
		d(a[i],i,1);
	}
	cout<<ans;
	return 0;
}
