#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 3; i <= n; i++){
		long long t = 1;
		for(int j = n, k = i; j > i, k >= 1; j--, k--) t *= j, t /= k;
		ans += t;
		ans %= 998244353;
	}
	cout << ans;
	return 0;
}