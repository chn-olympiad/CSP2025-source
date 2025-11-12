#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e5+5;

int n,k;
int a[N];
int sum[N];
int ans;

int dp[2<<22];

int rg(int l,int r) {
	return sum[r] ^ sum[l-1];
}

int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
	}
	
	memset(dp,-1,sizeof(dp));
	
	dp[0] = 0;
	int l = 0;
	for(int i = 1;i <= n;++i) {
		if(dp[sum[i]^k] != -1 && dp[sum[i]^k] >= l) {
			++ans;
			l = i;
		}
		dp[sum[i]] = i;
	}
	cout << ans;
	return 0;
}