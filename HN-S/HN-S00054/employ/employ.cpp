#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll ans;
string s;
int c[505];
int vis[505];
int a[505];
void dfs(int x) {
	if(x > n) {
		int sum = 0,out = 0;
		for(int i=1; i<=n; i++) {
			if(s[i] == '0') {
				out++;
				continue;
			}
			if(out >= c[a[i]]) {
				out++;
				continue;
			}
			sum++;
		}
		if(sum >= m) {
			ans = (ans+1)%998244353;
		}
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i]) {
			continue;
		}
		vis[i] = 1;
		a[x] = i;
		dfs(x+1);
		vis[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = " "+s;
	bool ok = true;
	for(int i = 1; i<=n; i++) {
		if(s[i] != '1') {
			ok = false;
		}
	}
	for(int i=1; i<=n; i++) {
		cin >> c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
