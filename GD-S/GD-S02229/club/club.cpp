// 枚举最多的那个，把剩下两个压成一个，然后就变成选n/2个1，选n/2个2 
// 算了先写T2 
// 当前70~80pts，代码正确 
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
// pipilong2024，我喜欢你！
int a[100005], b[100005], c[100005];
int dp[205][205][205];
int n;

#define a xingzhiB_a
#define b xingzhiB_b
#define n xingzhiB_n
int a[100005][4];
int b[100005];
int n;
int solve2(int idx){
	for(int i = 1; i <= n; i++){
		int mx = 0;
		for(int j = 1; j <= 3; j++){
			if(j != idx){
				mx = max(mx, a[i][j]);
			}
		}
		b[i] = mx - a[i][idx];
	}
	int ans = 0;
	sort(b + 1, b + n + 1, greater <int>());
	for(int i = 1; i <= n; i++) ans += a[i][idx];
	for(int i = 1; i <= n / 2; i++) ans += b[i];
	memset(b, 0, sizeof(b));
	return ans;
}
#undef a
#undef b
#undef n
void solveB(){
	xingzhiB_n = n;
	for(int i = 1; i <= n; i++){
		xingzhiB_a[i][1] = a[i];
		xingzhiB_a[i][2] = b[i];
		xingzhiB_a[i][3] = c[i];
	}
	int ans = 0;
	for(int i = 1; i <= 3; i++){
		ans = max(ans, solve2(i));
	}
	cout << ans << '\n';
}



void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	if(n > 200){
		solveB();
		return;
	}
	memset(dp, -63, sizeof(dp));
	dp[0][0][0] = 0;
	int ans = 0;
	for(int eee = 1; eee <= n; eee++){
		for(int i = n; i >= 0; i--){
			for(int j = n; j >= 0; j--){
				for(int k = n; k >= 0; k--){
					if(i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[eee]);
					if(j) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + b[eee]);
					if(k) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + c[eee]);
					if(i + j + k == n && max(i, max(j, k)) <= n / 2){
						ans = max(ans, dp[i][j][k]);
					}
				}
			}
		}
	}
	
	cout << ans << '\n';
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	cout.flush();
	
	return 0;
}

