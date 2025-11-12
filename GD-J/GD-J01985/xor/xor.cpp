#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7, maxs = (1 << 21);
int dp[maxn], a[maxn], mx[maxn];
int pos[maxs];
int n, k;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		sum = sum ^ a[i];
		int fl = pos[k ^ sum];
		if(fl != 0) dp[i] = mx[fl] + 1;
		mx[i] = max(ans, dp[i]), ans = max(ans, dp[i]), pos[sum] = max(pos[sum], i);
	}
	cout << mx[n] << endl;
	return 0;
}
