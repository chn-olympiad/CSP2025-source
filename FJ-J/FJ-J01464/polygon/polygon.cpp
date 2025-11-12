#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5025],dp[5025][5025],sum1,temp,cnt,inv[114514],qwq[114514];
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		dp[i-1][0]=1;
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	inv[0]=1;
	for(int i=1;i<=n;i++)
	inv[i]=inv[i-1]*i%998244353;
	for(int i=3;i<=n;i++)
	{
		temp=1;
		for(int j=n-i;j<=n;j++)
		temp=temp*j%998244353;
		temp/=inv[i];
		sum1+=temp;
		sum1%=998244353;
	}
//	cout<<sum1;
//temp=1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=5000; j++) {
			dp[i][j]=dp[i-1][j];
			if(j>=a[i])
				if(dp[i-1][j-a[i]])
					dp[i][j]++;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=a[i]; j++) {
			cnt+=dp[i-1][j];
		}
		cnt+=i-2;
	}
	cnt-=n;
	if(a[n]>a[n-1]+a[n-2])
	cnt=1;
	cout<<sum1-cnt;
	return 0;
}

//正难则反
//考虑是否能算出M>=3且不合法的方案数
//接着求出总的合法的方案数
//总的方案数是容易求的
//重点在于如何求不合法的方案数
//考虑枚举不合法方案中的最大边
//哇这就涉及到神秘的预处理了
//诶不对
//诶真坏吧
//形式化的，给定 n 个数，你要构造一个长度大于等于三的串，且使得串中最大的数小于串中其他的数之和
//显然可以枚举最大的数，这一层
//时间复杂度为 O(N)
//接下来的问题显然就是正着算还是反着算
//考虑到很多方案会被重复选择，所以可以预处理
//我们先考虑反着求
//注意到总和大于maxa的方案对于反求没有意义
//同时又注意到我们可以排序后递推
//延续上面，我们可以搞出一个N方状物预处理可能的不合法方案
//O(NM)预处理是可做的
//想想咋实现
//预处理写好了这下
//then？
//
