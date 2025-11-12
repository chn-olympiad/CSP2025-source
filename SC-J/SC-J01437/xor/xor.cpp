#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;

int n,k,a[N],pre[N];

int dp[N];

signed main() {
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) ,cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		pre[i] = pre[i-1] ^ a[i];
	}
	memset(dp,0,sizeof(dp));
	for(int i =1;i <= n;i++) {
		dp[i] = max(dp[i],dp[i-1]);
		for(int j = i;j >= 1;j--) {
			if((pre[i] ^ pre[j-1]) == k) {
				dp[i] = max(dp[i],dp[j-1] + 1);
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}