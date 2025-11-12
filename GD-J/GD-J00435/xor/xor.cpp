#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 5e5 + 5;
int arr[maxn];
int pre[maxn];
int dp[maxn];
int n,k;
int pre_map[1<<20];
void readin() {
	memset(pre,0,sizeof pre);
	memset(pre_map,-1,sizeof pre_map);
	cin>>n>>k;
	pre_map[0]=0;
	for(int i = 1; i<=n; ++i) {
		cin>>arr[i];
		dp[i] = dp[i-1];
		if(pre_map[pre[i] ^ k]!=-1)
			dp[i] = max(dp[i],pre_map[pre[i] ^ k] + 1);
		pre[i] = pre[i-1] ^ arr[i];
		pre_map[pre[i]]=dp[i];//只记录最右边的
	}
	cout<<dp[n];
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("xor_by_myself.in","r",stdin);
	readin();
	return 0;
}

