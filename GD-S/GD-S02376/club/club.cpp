#include<bits/stdc++.h>
#define int long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout) 
using namespace std;
const int N = 1e5 + 10;
int a1[N], a2[N], a3[N], ans;
int fl[N], dp[N];
void dfs(int u, int n1, int n2, int n3, int n, int cnt){
	if(cnt + fl[n] - fl[u - 1] <= ans) return;
	if(n1 > n / 2) return;
	if(n2 > n / 2) return;
	if(n3 > n / 2) return;
	if(u == n){
		ans = max(ans, cnt);
		return;
	}
	dfs(u + 1, n1 + 1, n2, n3, n, cnt + a1[u + 1]);
	dfs(u + 1, n1, n2 + 1, n3, n, cnt + a2[u + 1]);
	dfs(u + 1, n1, n2, n3 + 1, n, cnt + a3[u + 1]);
}
signed main(){
	fin("club.in");
	fout("club.out");
	int T;
	cin >> T;
	while(T--){
		int n;
		ans = 0;
		cin >> n;
		if(n <= 200){
		memset(fl, 0, sizeof fl);
		for(int i = 1; i <= n; i++){
			cin >> a1[i] >> a2[i] >> a3[i];
			fl[i] = fl[i - 1] + max(a1[i], max(a2[i], a3[i]));
		}
		dfs(0, 0, 0, 0, n, 0);
		cout << ans << '\n';
		}else{
			int cnt1 = 0, cnt2 = 0;
			memset(dp, 0, sizeof dp);
			for(int i = n, fl = 0, n1 = 0, n2 = 0, n3 = 0; i >= 1; i--){
				if(n1 + 1 <= n / 2) if(dp[i + 1] + a1[i] > dp[i]) dp[i] = dp[i + 1] + a1[i], fl = 1;
				if(n2 + 1 <= n / 2) if(dp[i + 1] + a2[i] > dp[i]) dp[i] = dp[i + 1] + a2[i], fl = 2;
				if(n3 + 1 <= n / 2) if(dp[i + 1] + a3[i] > dp[i]) dp[i] = dp[i + 1] + a3[i], fl = 3;
				if(fl == 1) n1++, cnt1 += a1[i];
				if(fl == 2) n2++, cnt1 += a2[i];
				if(fl == 3) n3++, cnt1 += a3[i];
//			cout << n1 << ' ' << n2 << ' ' << n3 << ' ' <<cnt <<  '\n';
			}
			memset(dp, 0, sizeof dp);
			for(int i = 1, fl = 0, n1 = 0, n2 = 0, n3 = 0; i <= n; i++){
				if(n1 + 1 <= n / 2) if(dp[i - 1] + a1[i] > dp[i]) dp[i] = dp[i - 1] + a1[i], fl = 1;
				if(n2 + 1 <= n / 2) if(dp[i - 1] + a2[i] > dp[i]) dp[i] = dp[i - 1] + a2[i], fl = 2;
				if(n3 + 1 <= n / 2) if(dp[i - 1] + a3[i] > dp[i]) dp[i] = dp[i - 1] + a3[i], fl = 3;
				if(fl == 1) n1++, cnt2 += a1[i];
				if(fl == 2) n2++, cnt2 += a2[i];
				if(fl == 3) n3++, cnt2 += a3[i];
//			cout << n1 << ' ' << n2 << ' ' << n3 << ' ' <<cnt <<  '\n';
			}
			cout << max(cnt1, cnt2) << '\n';
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
