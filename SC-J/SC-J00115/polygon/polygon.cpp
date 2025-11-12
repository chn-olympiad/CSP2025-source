#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const long long mod=998244353;
int n;
int a[N];
long long dp[N];
int c[N];
int lowbit(int x)
{
	return (-x)&x;
}
void update(int x,int w)
{
	for(int i=x;i<N;i+=lowbit(i))
	{
		c[i]+=w;
	}
	return ;
}
long long query(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
	{
		ans+=c[i];
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) dp[i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		if(a[i]<=a[j]*2 && a[i]>=a[j]) dp[i]=(dp[i]+dp[j])%mod;
	}
	long long tmp1=0;
	for(int i=1;i<=n;i++)
	{
		tmp1=(tmp1+i-1-query(a[i]-1))%mod;
		update(2*a[i],1);
	}
	long long ans=0;
	//for(int i=1;i<=n;i++) cout<<dp[i]<<endl;
	for(int i=1;i<=n;i++) ans=(ans+dp[i])%mod;
	//cout<<tmp1<<endl; 
	printf("%lld",((ans-n-tmp1)%mod+mod)%mod);
	return 0;
}