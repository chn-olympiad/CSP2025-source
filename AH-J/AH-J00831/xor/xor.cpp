#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], rec[500005];
long long b[500005], ans, dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		int pos = b[i] ^ k;
		if(!pos) dp[i] = 1;
		pos = rec[pos];
		if(pos) {
			dp[i] = max(dp[i], dp[pos] + 1);
			dp[i] = max(dp[i], dp[i - 1]);
		} else dp[i] = max(dp[i], dp[i - 1]);
		pos = b[i];
		rec[pos] = i;
	}
	cout<<dp[n]<<endl;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
