#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn = 5e5 + 5;
int n, k;
int a[maxn];
int pre[maxn];
int dp[1005][1005];
int f[1005];
void init() {
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] ^ a[i];
}
// O(n ^ 2)
void solve1() {
	init();
	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = i; j >= 1; j--) {
			if ((pre[i] ^ pre[j - 1]) == k) {
				dp[i][j] = f[j - 1] + 1;
//				cout << i << ' ' << j << ' ' << (pre[i] ^ pre[j - 1]) << endl;
			}	
			else {
				dp[i][j] = f[j - 1];
			}
			mx = max(mx, dp[i][j]);
		}
		f[i] = mx;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
}
// 对于每一个二进制进行进位 
// 选前 i 个且第 j 位是 1 的个数 
int dp1[maxn]; // 以第 i 个数为结尾的最大值 
int f1[maxn]; // 第 i 个数要到第几个才能变成 k  
map<int, int> mp; 
void init1() {
	init();
	mp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int nd = pre[i] ^ k;
//		cout << nd << ' ' << pre[i] << endl;
		if (!mp.count(nd)) f1[i] = -1;
		else f1[i] = mp[nd] + 1;
		mp[pre[i]] = i;
	}
//	cout << endl;
}
void solve() {
	init1();
	for (int i = 1; i <= n; i++) {
//		cout << f1[i] << ' ';
		dp1[i] = dp1[i - 1];
		if (f1[i] == -1) {
			continue;
		}
		dp1[i] = max(dp1[i], dp1[f1[i] - 1] + 1);
	}
//	cout << endl;
	cout << dp1[n] << endl;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n <= 1000) {
		solve1();
	}
	else {
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
