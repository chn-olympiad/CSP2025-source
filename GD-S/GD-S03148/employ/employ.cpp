#include<bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n, m;
string s;
int cnt;
int p[510];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> p[i];
	sort(p + 1, p + n + 1);
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') cnt++;
	}
	if(cnt < m) cout << 0;
	else if(cnt == n) {
		long long ans = 1;
		for(int i = n; i >= 1; i--) ans = ans * i % N;
		cout << ans;
	} else cout << N;
	return 0;
}
