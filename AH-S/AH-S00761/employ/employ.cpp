#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const int N = 5e2 + 1, MOD = 998244353;
ll n, m, c[N];
string s;
void Subtask1() {
	ll ans = 0, t[12];
	for(int i = 1; i <= n; ++ i) t[i] = i;
	do {
		ll reject = 0, pass = 0;
		for(int i = 1; i <= n; ++ i) {
			if(s[i] == '0') ++ reject;
			else if(s[i] == '1') {
				if(reject >= c[t[i]]) ++ reject;
				else if(reject < c[t[i]]) ++ pass;
			}
			if(pass >= m) break;
		}
		if(pass >= m) ++ ans;
	} while(next_permutation(t + 1, t + n + 1));
	cout << ans % MOD;
	return;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	s = '#' + s;
	for(int i = 1; i <= n; ++ i) cin >> c[i];
	if(n <= 10) Subtask1();
	return 0;
}
