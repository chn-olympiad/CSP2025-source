#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],dp[500005];
vector<long long>v[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(false);
	cin>>n>>k;
	v[0].push_back(0);
	for(long long i=1;i<=n;i++) cin>>a[i],s[i]=a[i]^s[i-1],v[s[i]].push_back(i);
	for(long long i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(long long j=0;j<v[s[i]^k].size();j++)
		{
			if(v[s[i]^k][j]>=i) break;
			dp[i]=max(dp[i],dp[v[s[i]^k][j]]+1);
		}
	}
	cout<<dp[n];
	return 0;
}
//8:40 创建文件。 
//9:31 把后两题看了，今年 J 组好像很简单的样子 
//9:36 欸嘿，这题不是大模拟，我的 CSP 有救了 
/*9:56
首先，我们要找到方程 x xor n = k 的解
解得 x = n xor k 
因此，对于任意 j ，都可以找到 i (0 < i < j <= n) ，
使 a_i = a_j xor k ，从而有区间 [i+1,j] 的权值为 k。
*/ 
//10:47 丸辣！虽然样例 A 了，但是样例 6 超时了 
//10:50 不做了，预计黄，感觉到不了绿，估计 60pts 
