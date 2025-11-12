#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n,k,ans;
int a[N];
int b[N];
int dp[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		bool f = false;
		int j,xorr = 0;
		for(j = i;j <= n;j++){
			xorr = xorr ^ a[j];
			if(xorr == k){
				f = true;
				break;
			}
		}
		if(f){
			b[i] = j;
		}
	}
	for(int i = 1;i <= n;i++){
		if(b[i]){
			dp[i] = 1;
		}else{
			continue;
		}
		for(int j = 1;j <= i;j++){
			if(b[j] && b[j] < i){
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		ans = max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}
