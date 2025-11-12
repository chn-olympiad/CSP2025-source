#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010];
int dp[5010];
int ans=0;
const int mod=998244353;
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
unordered_map<int,int> m;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],m[a[i]]++;
	sort(a+1,a+1+n,
	[](int a,int b)
	{
		return a>b;
	});
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=5000;j>=a[i];j--)dp[j]+=dp[j-a[i]];
	}
	for(int i=1;i<=n;i++)
	{
		int su=0;
		for(int j=0;j<=a[i];j++)su+=dp[j],su%=mod;
		su-=m[a[i]];
		m[a[i]]--;
		su=qpow(2,n-i)-su;
		su%=mod;
		su+=mod;
		su%=mod;
		ans+=su;
		ans%=mod;
	}
	cout<<ans;
}//O(n^2)
/*
9:34
秒了前三题
发现不会第四题
前来写俳句

不闹了。

9:46
发现 D 可以推成背包。
想到三次方做法。

10:00
写出三次方做法。

10:10左右
想到正解。

10:25
打完正解。

不知道干什么。
我要上迷惑行为。
*/
