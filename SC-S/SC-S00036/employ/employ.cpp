#include<bits/stdc++.h>
using namespace std;
const int P = 998244353;
int n, m, a[31], b[31], c[31];
long long ans = 0;
bool t[31];
string s;
int qpl(int d) {
	long long y = 1, cnt = 1;
	for (int i = 0; i < d; i++) {
		if (a[i] != 0) {
			y = y*cnt % P;
			cnt++;
		}
	}
	return y;
}
void dfs(int k) {
	if (k >= m) {
		ans += qpl(n - m) % P;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (t[i] == false && a[i] > c[k]) {
			t[i] = true;
			dfs(k + 1);
			t[i] = false;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			c[i]++;
			f = false;
		}
		c[i] += c[i - 1];
	}
	if (f == true) {
		cout << qpl(n);
		return 0;
	}
	ans = 0;
	dfs(0);
	cout << ans;
}