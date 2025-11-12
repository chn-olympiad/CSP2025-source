#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=5e5+5;
int n,k,a[N],pre[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if(dp[j-1]+1<=dp[i])break;
			if((pre[i]^pre[j-1])==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
	}
	cout<<dp[n]<<'\n';
	return 0;
}
/*
note:
异或和可以用前缀和处理 

11:08 O(n^2) 算法通过样例 1~5，ex_6 TLE(AC)。 
11:19 神秘优化通过 ex_6 
*/
/*
4 2
2 1 0 3
(ans=2)
4 3
2 1 0 3
(ans=2)
4 0
2 1 0 3
(ans=1)
*/

