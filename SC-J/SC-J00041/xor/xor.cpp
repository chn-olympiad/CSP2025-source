#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],sum[500005];
vector<int> vc[4000005];
long long dp[500005];
//if:sum[i]^sum[j]==k->k^sum[j]==sum[i];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	vc[0].push_back(0);
	for(int i=1; i<=n; i++){
		cin >> a[i];
		sum[i] = sum[i-1]^a[i];
		vc[sum[i]].push_back(i);
	}
	for(int i=1; i<=n; i++){
		int kk = k^sum[i];
		dp[i] = dp[i-1];
		for(int j=0; j<vc[kk].size(); j++){
			if(vc[kk][j]>=i) break;
			dp[i] = max(dp[i],dp[vc[kk][j]]+1);
		}
	}
	cout << dp[n];
	return 0;
}