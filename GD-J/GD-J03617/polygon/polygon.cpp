#include <cstdio>
#define mod 998244353
using namespace std;
long long ans=0;
int n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int j=i+1,sum=a[i],Max=0;
		while(j<=n)
		{
			sum+=a[j];
			if(a[j]>Max) Max=a[j];
			if(j-i+1>=3)
			{
				if(sum>Max*2) ans=(ans+1)%mod;
			}
			j++;
		}
		sum=0;Max=0;
	}
	printf("%lld",ans);
	return 0;
}
