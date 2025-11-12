#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans=0,l[500005],r[500005],c=0,dp[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		long long s=a[i],z=0;
		for(int j=i+1;j<=n;j++)
		{
			if(s==k)
			{
				l[++c]=i,r[c]=j-1;
				break;
			}
			s=(s^a[j]);
		}
		if(s==k) l[++c]=i,r[c]=n;
	}
	for(int i=1;i<=c;i++)
	{
		dp[i]=1;
		for(int j=i-1;j>0;j--)
			if(r[j]<l[i]&&l[j]!=l[i]) dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]);
	}
	printf("%lld",ans);
	return 0; 
} 
//好渴，我要喝水！！！！！
//9:48 我要喝水！！！ 
//11:21 不渴了，想去洗手间 
