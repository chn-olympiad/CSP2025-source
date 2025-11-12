#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 1;
bool vis[maxn];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[n + 1];
	int beg = 1, ans = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			cnt++;
			vis[i] = true;
		}
	} 
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			beg = i + 1;
			ans = 0;
			continue;
		}
		ans ^= a[i];
		if (ans == k) {
			beg = i + 1;
			cnt++;
			ans = 0;
		}
	}
	cout << cnt << endl; 
}
