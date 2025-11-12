#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],dp[5005][5005],ans;
const long long mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(false);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=5001;j>=0;j--)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			if(j>a[i]) ans=(ans+dp[i][j])%mod;
			dp[i][min(5001ll,j+a[i])]=(dp[i][min(5001ll,j+a[i])]+dp[i-1][j])%mod;
		}
	}
	cout<<ans;
	return 0;
}
//8:41 创建文件。 
/*10:54 
题意：
给定长度为 n 的数组 a，从中选择 m 个放在数组 l。
有多少种不同的方案使得 Σ^m_i=1 l_i> 2*max^m_i=1 l_i？
答案模998244353

注意到 n<5000 ，尝试 O(n^2) (容易被卡常啊)
11:09 内存可能会爆，量力而行吧 
11:11 估计此题绿，但肯定到不了蓝（真的吗） 
11:54 结束前两分钟过完所有样例！！！！！ 
*/
