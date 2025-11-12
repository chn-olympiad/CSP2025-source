#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int MR = (1 << 20) + 5;
const int MAXN = 5e5 + 5;
int a[MAXN],n,k;
int dp[MAXN],tong[MR];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i],a[i] ^= a[i-1];
	memset(tong,-1,sizeof(tong));
	tong[0] = 0;
	for(int i = 1;i <= n;i++){
		dp[i] = max(dp[i-1],tong[a[i] ^ k] + 1);
		tong[a[i]] = max(tong[a[i]],dp[i]);
		// cerr << dp[i] << '\n';
		
		// dp[i] = dp[i-1];
// 		
		// for(int j = 1;j <= i;j++)
			// if((a[i] ^ a[j-1]) == k)
				// dp[i] = max(dp[i],dp[j-1] + 1);
		// cerr << dp[i] << '\n';
	}
	cout << dp[n];
	return 0;
}