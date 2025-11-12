#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000010;
int a[N], b[N], dp[N];
struct kun {
	int l, r;
}suan[N];
bool amp[N];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	b[1] = a[1];
	for(int i = 2;i <= n;i ++) b[i] = b[i - 1] ^ a[i];
	for(int i = 1;i <= n;i ++) {
		if(i == 1) {
			for(int j = 1;j <= n;j ++) {
				if(b[j] == k) {suan[i].l = i, suan[i].r = j, amp[i] = 1;break;}
			}
		} else {
			for(int j = i;j <= n;j ++) {
				if((b[j] ^ b[i - 1]) == k) {suan[i].l = i, suan[i].r = j, amp[i] = 1;break;}
			}
		}
	}
	for(int i = 1;i <= n;i ++) {
		if(!amp[i]) {
			dp[i] = max(dp[i], dp[i - 1]);
			continue;
		} else {
			dp[suan[i].r] = max(dp[suan[i].r], dp[i - 1] + 1);
		} dp[i] = max(dp[i], dp[i - 1]);
	} cout << dp[n] << endl;
	return 0;
} 

