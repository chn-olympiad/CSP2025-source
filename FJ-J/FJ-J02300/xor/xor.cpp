#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long ans=0;
	long long a[n+10];
	long long b[n+10];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		b[i]=b[i-1]^a[i];
	}
	int sum=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j>sum;j--)
		{
			if((b[i]^b[j-1])==k)
			{
				ans++;
				sum=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
