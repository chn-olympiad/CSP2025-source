#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n;
long long k;
long long a[N];
int maxtot, sum, ans;
void dfs(int x, int tot, int num) {
	if (tot == maxtot) {
		//cout << "ggggggggggggg x:" << x << " tot:" << tot << " num:" << num << "\n";
		sum = maxtot;
		//cout << sum << "\n";
		return;
	}
	for (int i = x; i <= n; i++) {
		for (int j = x; j <= i; j++) {
			//cout << num << " " << a[j] << "\n";
			num ^= a[j];
		}
		//cout << "i:" << i << " tot:" << tot + 1 << " num:" << num << "\n";
		if (num == k) {
			//cout << "winnn i:" << i << " tot:" << tot + 1 << " num:" << num << "\n";
			dfs(i + 1, tot + 1, num);
		}
		num = 0;
	}
}
int numm[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum = 0;
		maxtot = i;
		//cout << "数量:" << maxtot << "\n";
		dfs(1, 0, 0);
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}