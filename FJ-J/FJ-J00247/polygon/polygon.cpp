#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],dp[2][10005][2],ans,maxx;
//bool pd[25];
//void dfs(int now){
//	if(now>n){
//		int maxx=0,sum=0;
//		for(int i = 1;i<=n;i++)
//			if(pd[i])
//				maxx=max(maxx,a[i]),sum+=a[i];
//		if(sum>maxx*2) ans++;
//		return;
//	}
//	pd[now]=1;
//	dfs(now+1);
//	pd[now]=0;
//	dfs(now+1);
//}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
//	if(n<=20){
//		dfs(1);
//		return cout<<ans,0;
//	} 
	sort(a+1,a+1+n);
	dp[0][0][0]=1;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=maxx*2+1;j++)
			dp[i&1][j][0]=(dp[i&1^1][j][0]+dp[i&1^1][j][1])%mod,
			dp[i&1][j][1]=0;
		for(int j = maxx*2+1;j>=a[i];j--)
			(dp[i&1][j][1]+=dp[i&1^1][j-a[i]][0]+dp[i&1^1][j-a[i]][1])%=mod;
		for(int j = maxx*2+2-a[i];j<=maxx*2+1;j++)
			(dp[i&1][maxx*2+1][1]+=dp[i&1^1][j][0]+dp[i&1^1][j][1])%=mod;
		for(int j = a[i]*2+1;j<=maxx*2+1;j++)
			(ans+=dp[i&1][j][1])%=mod;
	}
	cout<<ans;
	return 0;
}
/*
8:50
前三题20min就秒了（嘻嘻） 
dp_i,j,k
表示到第i位，最大值为j，选或不选第i位的方案数(k)
考虑维护前缀和
到第i位，总和为j的方案数 
可以使用树状数组加速 
树状数组是错的
先打出75的暴力再说 
思路全错 
气死我了，先打了个40的暴力分 
继续猜状态
我可以先枚举最大值
然后考虑能够组合出多少状态
不递推 （开心,但是75pts） 
9:31分，宣布拿下75pts（yeah） 
接下来开始想正解 
发现一定不能在每一位求出和为j的方案数（会TLE）
有什么转化的方法？
9:44我有一计：大于maxx*2的不算了，统一当作 maxx*2+1 
9:55 1个半小时，宣布AK 
顺手记录一下每一道题完成的时间
8:31:T1
8:35:T2
8:50:T3
9:55:T4
千万别炸啊qwq 
最后一次的J组，不留遗憾 
对拍跑了近两个小时，没找出问题 
不对700Mb会MLE
最后十分钟改过来了，改成了滚动数组 
悬 
The life you want.
*/
