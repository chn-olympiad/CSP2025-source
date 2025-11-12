#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5, P = 998244353;
int a[N];
int n, ans;

void dfs(int u, int ma, int sum, int cnt) {
	cnt++;
	int t = a[u];
	sum += t;
	ma = max(ma, t);
	if(cnt >= 3 && sum > 2 * ma) {
		ans++;
		ans %= P;
	}
	
	for(int i = u + 1;i <= n;i++) {
		dfs(i, ma, sum, cnt);
	}
	return;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n ;
	for(int i = 1;i <= n;i++) {
		cin >> a[i] ;
	}
	
	for(int i = 1;i <= n;i++) {
		dfs(i, 0, 0, 0);
		
	}
	
	cout << ans ;
	
	return 0;
}
