#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long sum[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,p,maxn=LLONG_MIN;
	cin>>n>>p;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(long long i=1;i<=n-1;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			for(long long k=i;k<=j-1;k++)
			{
				for(long long g=k+1;g<=j;g++)
				{
					long long b=sum[i-1]^sum[k];
					long long c=sum[g-1]^sum[j];
					if(b==c&&b<=p)
					{
						maxn=max(maxn,b);
					}
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}
