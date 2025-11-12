#include<bits/stdc++.h>
using namespace std;
long long a[500002];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n=0,k=0,ans=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++)a[i]=a[i]^a[i-1];
	for(long long i=1;i<=n;i++)
		for(long long j=i;j<=n;j++)
		{
			long long g=a[i-1]^a[j];
			if(g==k)
			{
				ans++;
				i=j;
				break;
			}
		}
	cout<<ans;
	return 0;
}

