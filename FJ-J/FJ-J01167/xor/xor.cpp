#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5;

int sum[N],dp[N]; // dp[i]: 1~i的区间数量最大值

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		sum[i]=sum[i-1]^x;
	}
	for(int r=1;r<=n;r++){ // 右端点
		int l=r; // 左端点
		while(l>=1){
			// 找到最大的左端点
			if(l==1 && sum[r]==k) break;
			else if(l>1 && (sum[r]^sum[l-1])==k) break;
			l--; // 当l<1时, 即正常退出, 没找到
		}
		if(l>=1) dp[r]=max(dp[l-1]+1,dp[r-1]);
		else dp[r]=dp[r-1];
	}
	cout<<dp[n]<<"\n";
	return 0;
}
/*
目前出现的问题:
1.时间复杂度O(n^2)太高了, 需要优化
2.这题不是贪心, 举个例子:
  4 0
  2 0 0 2
此题应为2, 选[2,2]和[3,3] 2个区间可得
但贪心会输出1, 它是选[1,4] 1个区间

解法:
dp[i]: 1~i的区间数量最大值
dp[r]=max(dp[l-1]+1,dp[r-1]) // sum[r]^sum[x-1]=k, l=max{x...}
*/
