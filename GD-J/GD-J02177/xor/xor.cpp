#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 5e5 + 10;
int a[N];
int dp[1010][1010];
int vis[1010][1010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(a, 0, sizeof(0));
	memset(dp, 0, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	dp[1][1] = a[1];
	for(int i=1; i<=n; i++) {
		dp[i][i] = a[i];
		for(int j=i+1; j<=n; j++) {
			dp[i][j] = dp[i][j-1] ^ a[j];
		}
	}
	int high = -1, cnt = 0;
	for(int i=1; i<=n; i++) {
		bool flag = false;
		for(int j=i; j<=n; j++) {
			if(dp[i][j] == k && !flag && i > high) {
				flag = true;
				high = max(high, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}
