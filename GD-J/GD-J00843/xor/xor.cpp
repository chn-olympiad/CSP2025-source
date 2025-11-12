#include <iostream>
using namespace std;
const int N = 5 * 1e5 + 10;
long long n, k, a[N], sum[N], dp[N];
int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i - 1; j >= 1; j--){
			if(sum[i] ^ sum[j - 1] == k) dp[i] = max (dp[i], dp[j - 1] + 1);
		}
	}
	long long ans = -1;
	for(int i = 1; i <= n; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
