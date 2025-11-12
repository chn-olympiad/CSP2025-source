//GZ-S00008 贵阳市第十七中学 付昀泽
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sp setprecision
#define p_q priority_queue
int n, ans;
vector<vector<int> > a;
void dfs(int i, int j, int k, int res, int step) {
	if(step == n + 1) {
		ans = max(ans, res);
		return ;
	}
	if(i < n / 2)
	    dfs(i + 1, j, k, res + a[step][0], step + 1);
	if(j < n / 2)
	    dfs(i, j + 1, k, res + a[step][1], step + 1);
	if(k < n / 2)
	    dfs(i, j, k + 1, res + a[step][2], step + 1);
}
void solve() {
	ans = 0;
	cin >> n;
	a.resize(n + 1, vector<int> (3));
	for(int i = 1;i <= n;i++)
	    cin >> a[i][0] >> a[i][1] >> a[i][2];
	dfs(0, 0, 0, 0, 1);
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	    solve();
	return 0;
}
