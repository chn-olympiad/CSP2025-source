#include <bits/stdc++.h>
using namespace std;

long long n, a[5010], s;

void dfs(long long t, long long x, long long ans, long long cnt){
	if(t == n + 1){
		if(x >= 3 && ans > cnt * 2){
			s = (s + 1) % 998244353;
		}
		return;
	}
	dfs(t + 1, x + 1, ans + a[t], max(cnt, a[t]));
	dfs(t + 1, x, ans, cnt);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(long long i = 1; i < n - 1; i++){
		dfs(i + 1, 1, a[i], a[i]);
	}
	cout << s << endl;
	return 0;
}
