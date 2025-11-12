#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;
const int N = 5005;
int n;
int a[N];
int ans;
int dp[N];
int num[N];

int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		dp[a[i]]++;
		num[a[i]] = dp[a[i]];
	}
	
	sort(a+1,a+1+n);
	
	int t = (long long) n*(n-1)*(n-2) % mod;
	ans += t;
	for(int i = 4;i <= n;++i) {
		t = (long long)t*(n-i+1)%mod;
		ans += t;
		ans %= mod;
	}
	
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j < i;++j) {
			dp[i] += num[j]*dp[i-j];
		}
		
	}
	
	for(int i = 3;i <= n;++i) {
		for(int j = a[i]-1;j >= 0;--j) {
			ans -= dp[i];
		}
	}
	cout << ans;
	return 0;
}