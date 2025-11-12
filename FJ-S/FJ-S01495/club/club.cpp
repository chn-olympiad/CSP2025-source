#include <bits/stdc++.h>
#define endl "\n"
#define MAXN 100005
using namespace std;
int t, n, m[MAXN][3], ans=-1,pf1,pf2;
long long sum[MAXN];
bool vis[MAXN];
void solve();
void dfs(int, int, int ,int);
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> t;
	while(t--) solve();
	return 0;
}
void solve(){
	cin >> n;
	ans = -1;
	pf1 = 0,pf2 = 0;
	for (int i = 1;i <= n;i++){
		cin >> m[i][0] >> m[i][1] >> m[i][2];
		vis[i] = 0;
		sum[i] = sum[i - 1] + max(m[i][0], max(m[i][1], m[i][2]));
		pf1 = max(m[i][1], pf1);
		pf2 = max(m[i][2], pf2);
	}
	dfs(0, 0, 0, 0);
	cout << ans << endl;
	return;
}
void dfs(int cur, int a,int b,int c){
	if (a + b + c == n){
		ans = max(ans, cur);
		return;
	}
	for (int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		if (a < n / 2 && cur + sum[n] - sum[a + b + c] > ans) dfs(cur + m[i][0], a + 1, b, c);
		if ((pf1 || a >= n / 2) && b < n / 2 && cur + sum[n] - sum[a + b + c] > ans) dfs(cur + m[i][1], a, b + 1, c);
		if ((pf1 > 0 && (pf2 || a >= n / 2 || b >= n / 2)) && c < n / 2 && cur + sum[n] - sum[a + b + c] > ans) dfs(cur + m[i][2], a, b, c + 1);
		vis[i] = 0;
	}
}
