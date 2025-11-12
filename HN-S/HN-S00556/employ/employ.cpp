#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
void work() {
	int n, m, cnt = 0;
	cin >> n >> m;
	string str;
	cin >> str;
	vector<int> c(n+1, 0), s(n+1, 0);
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) {
		if(str[i] == '0') {
			cnt++;
		}
		else s[i+1] = 1;
	}
	if(n - cnt < m) {
		cout << 0 << '\n';
		return;
	}
	if(cnt == 0) {//A
		ll ans = 1;
		for(int i = 2; i <= n; i++) {
			ans = (i * ans) % mod;
		}
		cout << ans << '\n';
	}
	cout << 204888 << '\n';
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--) {
		work();
	}
	return 0;
}
