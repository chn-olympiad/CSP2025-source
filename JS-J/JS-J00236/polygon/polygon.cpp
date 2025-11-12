// JS-J00236
// XD

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[5005], ans, end__;
map<int, int> vis;
void dfs(int now, int su, int num, int max_){
	if (su > max_ * 2 && num >= 3){
		// cut << su + a[i] << " " << end__ << "\n";
		ans = (ans + 1) % 998244353;
	}
	// cout << now << " " << max__ << " " << su << " " << end__ << "\n";
	for (int i = now + 1; i <= n; ++i){
		dfs(i, su + a[i], num + 1, max(a[i], max_));
	}
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i){
		vis[a[i]] = i;
	}
	dfs(0, 0, 0, 0);
	/*
	for (int i = 1; i <= n; ++i){
		if (i < 3){
			continue;
		}
		if (i != vis[a[i]]){
			//cout << i << " " << a[i] << " " << vis[a[i]] << "\n";
			continue;
		}
		max__ = a[i];
		end__ = 2 * a[i];
		
		cout << i << " " << ans << "\n";
	}*/
	cout << ans;
	return 0;
}
