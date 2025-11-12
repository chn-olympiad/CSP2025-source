#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long b[1000010],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,t=0;
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i]^b[i-1];
		for(long long j=i;j>t;j--)
		{
			long long v=b[i]^b[j-1];
			if(v==k)
			{
				ans++;
				t=i;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

