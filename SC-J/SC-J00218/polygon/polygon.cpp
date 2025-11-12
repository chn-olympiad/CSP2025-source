//freopen
//feropen
/*
写不来，想法呼之欲出，但只能暴力
策略是容斥+dfs
估分360遗憾离场 
希望T1T2T3不要炸
希望S组能得一等
luoguuid:928435
*/
#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],flg=2,mod=998244353,ans;
void dfs(int num,int h)
{
	if(h>a[flg])return;
	if(num==flg){ans++;ans%=mod;return;}
	dfs(num+1,h);
	dfs(num+1,h+a[num]);
	return;
}
long long fst_pow(long long c)
{
	long long ans=1,ds=2;
	while(c)
	{
		if(c%2==1)ans=(ans*ds)%mod;
		c/=2;
		ds=(ds*ds)%mod;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		flg++;
		dfs(1,0);
	}
	long long p=(long long)(fst_pow(n)+mod-4)%mod;
	printf("%lld",(p+mod-ans)%mod);
	return 0;
}