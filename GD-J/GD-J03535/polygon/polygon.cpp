#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10,mod=998244353;
int a[N];
int dp[2][N];
int qpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int ans=0;
	int n;
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+qpow(2,i-1))%mod;
		for(int j=0;j<=a[i];j++) ans=(ans-dp[(i&1)^1][j]+mod)%mod;
		memset(dp[i&1],0,sizeof(dp[i&1]));
		for(int j=0;j<=mx;j++)
		{
			dp[i&1][j]=dp[(i&1)^1][j];
			if(j>=a[i]) dp[i&1][j]=(dp[i&1][j]+dp[(i&1)^1][j-a[i]])%mod;
		}
	}
	cout<<ans;
	return 0;
}
/*
100pts
预估绿
9:06 AK!
发压缩包密码后先开了这题
正解一眼看出来了qwq
9:22 Linux 下测完样例，没问题 
9:28 将注释修改格式为 UTF-8，测了下 Linux 下可以过编
*/ 
