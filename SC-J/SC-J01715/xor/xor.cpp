#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)



const int mod = 7 + 1e9;
const int N = 3 + 5e5;

mt19937 rnd(time(NULL));


int n, k;
int a[N], pre[N];
int dp[N];
int cnt[1 << 20];

int main() {
//	freopen("D:\\work\\xor\\xor6.in", "r", stdin);
//	freopen("D:\\work\\xor\\xor6.out", "w", stdout);	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] ^ a[i];
	}
	
	memset(cnt, -0x3f, sizeof(cnt));
	
	for (int i = 1; i <= n; ++i) {
		cnt[pre[i - 1]] = max(cnt[pre[i - 1]], dp[i - 1]);
		dp[i] = max(cnt[pre[i] ^ k] + 1, dp[i - 1]);
//		cout << i << "   " << dp[i] << endl;
	}
	cout << dp[n];
	
	return 0;
} 