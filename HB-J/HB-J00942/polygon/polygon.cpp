#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n-2;i++)
	{
		for(long long j=i+1;j<=n-1;j++)
		{
			for(long long k=j+1;k<=n;k++)
			{
				long long maxn=max(a[i],a[j]);
				maxn=max(maxn,a[k]);
				if((a[i]+a[j]+a[k])>maxn*2) ans++;
				else break;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}
