#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[5001];
bool vis[5001];
ll ans = 0;
void dfs(int len, int cnt, ll mx, ll s) {
	if(cnt == len) {
		if(s > 2 * mx) {
			ans++;
			va.push_back(v);
		}
		ans %= 998244353;
		return ;
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = true;
			v.push_back(i);
			dfs(len, cnt + 1, ((a[i] > mx) ? a[i] : mx), s + a[i]);
			v.pop_back();
			vis[i] = false;
		}
	}
}
int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	for(int i = 3; i <= n; i++) {
		memset(vis, false, sizeof vis);
		dfs(i, 0, 0, 0);
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
