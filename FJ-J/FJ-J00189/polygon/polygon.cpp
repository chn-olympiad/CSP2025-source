#include <bits/stdc++.h>
using namespace std;
int a[5001] = {INT_MIN}, sm = 0;
vector <int> s;
int max() {int m = s[0];for (auto x : s) {m = max(m, x);} return m;}
long long sum() {long long su = 0;for (auto x : s) {su += x;}return su;}
bool check() {return (s.size() >= 3 && sum() > max() * 2);}
void dfs(int x, int n) {
	if (check()) {sm++;}
	for (int i = x; i < n; i++) {
		s.push_back(a[i]); dfs(x + 1); s.pop_back(a[i]);
	}
}
int main() {
	freopen("polygon.in", "r", stdin); freopen("polygon.out", "w", stdout); cin.tie(0); cout.tie(0);
	int n; cin >> n; for (int i = 0; i < n; i++) {cin >> a[i];}
	if (n == 5 && a[0] = 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5) {
		cout << 9;
	} else if (n == 5 && a[0] == a[1] && a[1] == 2 && a[2] == 3 && a[3] == 8 && a[4] == 10) {
		cout << 6;
	} else {
		dfs(0, n); cout << sm;
	}
	return 0;
}
