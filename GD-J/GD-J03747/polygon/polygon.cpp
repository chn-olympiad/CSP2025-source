#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,a[5005],s[5005],sum[5000005],ans,l,cnt,p;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=3;i<=n;i++)
	{
		if(a[i]>=s[i-1])continue;
		cnt=0,p=i-1;
		for(int j=0;j<=p/2;j++)
		{
			l=1;
			for(int k=p;k>p-j;k--)
				l=(l*k/(p-k+1))%mod;
			cnt+=l;
		}
		cnt*=2;
		if(p%2==0){
			l=1;
			for(int k=p;k>p-(p/2);k--)
				l=(l*k/(p-k+1))%mod;
			cnt-=l;
		}
		ans=(ans+cnt)%mod;
		memset(sum,0,sizeof(sum));
		sum[0]=1;
		for(int j=1;j<i;j++)
			for(int k=a[i];k>=a[j];k--)
				sum[k]=(sum[k]+sum[k-a[j]])%mod;
		for(int j=0;j<=a[i];j++)
			ans=(ans+mod-sum[j])%mod;
	}
	printf("%lld",ans);
	return 0;
}
