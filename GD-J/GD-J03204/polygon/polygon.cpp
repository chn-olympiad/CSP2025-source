#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int md = 998244353;	
const int N = 5e3 + 10;
int n, a[N], ans, vis[N];
map<string,int> mp;
void dfs(int x, int s, int mx, int c, string ss) {
	if(x > n) {
		if(c >= 3 && mp[ss] == 0 && s > mx * 2) ans = (ans + 1 + md) % md;
		return;
	}
	string t = ""; int u = a[x];
	while(u) {
		t = char(u % 10 + '0') + t;
		u /= 10;
	}
	dfs(x + 1, s + a[x], max(mx, a[x]), c + 1, ss + t);
	dfs(x + 1, s, mx, c, ss);
}
int main() { 
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	dfs(1, 0, -1, 0, "");
	cout << ans;
	return 0;
} 
