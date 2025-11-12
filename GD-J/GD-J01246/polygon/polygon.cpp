#include<bits/stdc++.h>
using namespace std;
const long long moddd=998244353,N=5005;
int a[5005];
long long ans;
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++)
	{
		for(long long j=i+1;j<n;j++)
		{
			for(long long k=j+1;k<n;k++)
			{
				long long maxn=max(a[i],max(a[j],a[k]));
				long long num=a[i]+a[j]+a[k];
				if(num-maxn>maxn)
				{
					ans=(ans+1)%moddd;
				}
			}
		}
	}
	for(int i=4;i<n;i++)
	{
		int c=1;
		for(int x=n;n-x<=i;x--)
		{
			c*=x;
		}
		for(int y=1;y<=i;y++)
		{
			c/=y;
		}
		c%=moddd;
		ans=(ans+c)%moddd;
	}
	cout<<ans;
	return 0;
}

