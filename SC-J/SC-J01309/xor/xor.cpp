#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,now=-1,a[N],dp[N],sum[N];
int check(int step){
	for(int i=step;i>=max(1,now+1);i--){
		int num=sum[step]^sum[i-1];
		if(num==k){
			now=step;
//			cout<<i<<" "<<step<<"\n";
			return 1;
		}
	}
	return 0;
}
int main(){// DP思路+前缀和优化（期望100pts）
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];// 前缀和将区间异或值查询优化至O(1) 
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+check(i);
	}
	cout<<dp[n];
	return 0;
}
/*

4 2
2 1 0 3
2

4 3
2 1 0 3
2

4 0
2 1 0 3
1
*/