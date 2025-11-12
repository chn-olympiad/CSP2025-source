#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using LL=long long;
using VI=vector<int>;
using AR=array<int,2>;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;cin>>n>>k;//区间总长、区间个数和给定的k都在int以内 
	VI num(n+1),sum(n+1),dp(n+1);//输入的a，a的异或前缀和，区间个数子问题答案都在int以内 
	REP(i,1,n)cin>>num[i],sum[i]=sum[i-1]^num[i];//sum记录异或前缀和 
	unordered_map<int,int> mp;//mp下标是sum值，int以内 
	mp[0]=0;//初始状态，起始空区间异或和为0，最大空间个数为0 
	REP(i,1,n){
		int needval=sum[i]^k;//要求的sum[j] 
		dp[i]=dp[i-1];//第一种转移 
		if(mp.count(needval))dp[i]=max(mp[needval]+1,dp[i]);//只有当sum[j]可达时才能从sum[j]处转移，增加一个新的区间 
		mp[sum[i]]=max(mp[sum[i]],dp[i]);//更新sum[i]的最大值 
		ans=max(ans,dp[i]);//更新ans
		//实际上直接输出dp[n]应该就可以了，但是我不想想了全部最大值都取一遍肯定是对的 
	}
	cout<<ans;
	return 0;
}
//容易看出普通dp：
//定义sum[i]为从num[1]到num[i]的异或前缀和 
//定义dp[i]为到i为止能够选择的区间个数的最大值 
//那么dp[i]能够直接从dp[i-1]转移过来
//也能够选取一个j使得num[i]^num[j]=k，然后从dp[j]+1转移过来
//需要优化
//时间瓶颈来自dp[i]的第二种转移
//注意到异或运算的性质，num[j]实质上是被确定的
//因此我们可以将第二种转移改为：
//选取一个j使得num[j]=num[i]^k，然后从dp[j]+1转移过来
//进而改为
//选取一个j使得num[j]=num[i]^k，且dp[j]最大，从dp[j]+1转移过来
//因此要记录所有num[j]相同的j中dp[j]的最大值
//不管了不想想了直接开unordered_map了尽管我知道这道题直接用数组是可以的 
//11-01 09:02:24