#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
long long a[maxn], b[maxn], ans = 0, n, lim;
map<pair<int, int>, int> mp; 

void dfs(int x, int past, int sum, int maxx) {
	if(x > lim && sum > 2*maxx) {
		++ans;
		ans %= 998244353;
		return ;
	}
	if(x > lim) return ;
	for(int i=past+1; i<=n; i++) {
		b[x] = a[i];
		dfs(x+1, i, sum+a[i], a[i]);
	}
} 

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(lim=3; lim<=n; lim++) {
		dfs(1, 0, 0, 0);
	}
	cout << ans % 998244353;
	return 0;
}
