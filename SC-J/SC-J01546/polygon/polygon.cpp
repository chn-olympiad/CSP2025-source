#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5008;
int n,ans;
int a[N];
int add(int x,int y)
{
	return(x+y)%mod;
}
void dfs(int now,int mx,int sum)
{
	if(now>n)
	{
		if(mx*2<sum)
			ans=add(ans,1ll);
		return ;
	}
	dfs(now+1,max(mx,a[now]),sum+a[now]);
	dfs(now+1,mx,sum);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
不会的题写游记。。。
T1T2模拟秒了
T3马上就想到了n方dp做法，然后不知道怎么优化成n。。。就去写T4了
结果T4感觉很好想，但优化好难。。。就打了个40pts的暴力
接着。。。
就开始surf和小恐龙了
ps：
小恐龙头一次打到3000多
surf15000了
还有一个小时。。。
（没拿普一变猫娘
*/