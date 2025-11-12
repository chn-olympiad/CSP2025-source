#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
string s;
int a[510];
int ans;
bool vis[510];
//int rec[510];
void dfs(int t, int out) {
	if(out > n - m) return ;
	if(t > n) {
		++ans;
//		for(int i = 1; i <= n; i++) {
//			cout << rec[i] << ' ';
//		}
//		cout << endl;
		return ;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = true;
//		rec[t] = i;
		if(a[i] <= out || s[t] == '0') dfs(t + 1, out + 1);
		else dfs(t + 1, out);
		vis[i] = false;
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}



