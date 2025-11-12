#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1e5 + 2;

int _, n, ans, a[N];

int sum(vector <int> x) {
	int cnt = 0;
	for (int i = 0;i < x.size();i++) cnt += x[i];
	return cnt;
}

int max(vector <int> x) {
	int cnt = 0;
	for (int i = 0;i < x.size();i++) cnt = max(cnt, x[i]);
	return cnt;
}

void dfs(vector <int> x) {
//	for (int i = 0;i < x.size();i++) cout << x[i] << " ";
//	cout << endl; 
	if (x.size() >= 3 && sum(x) > 2 * max(x)) {
		ans++;
		if (ans >= 998244353) ans %= 998244353;
	}
	if (x.size() == n + 1) return;
	for (int i = x[x.size() - 1] + 1;i <= n;i++) {
		x.push_back(i);
		dfs(x);
		x.pop_back();
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	dfs({0});
	cout << ans << endl;
	return 0;
}

