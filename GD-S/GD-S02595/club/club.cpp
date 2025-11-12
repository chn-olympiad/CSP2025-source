#include <iostream>
#define endl "\n"
#define ll long long
using namespace std;
ll a[10001][4], n, maxn;
void dfs(ll b[4], ll x, ll ans) {
	if(b[1] > n / 2 || b[2] > n / 2 || b[3] > n / 2)return ;
	if(x > n) {
		maxn = max(maxn, ans);
		return ;
	}
	for(int i = 1; i <= 3; i++) {
		b[i]++;
		dfs(b, x + 1, ans + a[x][i]);
		b[i]--;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(ll i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		maxn = -1;
		ll tp[4] = {0, 0, 0, 0};
		dfs(tp, 0, 0);
		cout << maxn << endl;
	}
	return 0;
}