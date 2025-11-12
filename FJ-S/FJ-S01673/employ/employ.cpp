#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
const int mod = 998244353;
int n, m, c[501], l[501], cnt;
long long fact[501];
string s;
void init(){
	fact[0] = 1;
	for (long long i = 1; i <= n; i++){
		fact[i] = fact[i - 1] * i % mod;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	FILE("employ")
	cin >> n >> m;
	init();
	cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++){
		if (s[i] == '1'){
			l[++cnt] = i;
		}
	}
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	if (m == n){
		bool ans = true;
		for (int i = 1; i <= n; i++){
			ans &= !!c[i];
		}
		if (cnt == n && ans){
			cout << fact[n];
		} else {
			cout << "0";
		}
	} else if (m == 1){
		long long ans = 1, tmp = 0;
		for (int i = 1; i <= cnt; i++){
			ans *= max(0ll, upper_bound(c + 1, c + n + 1, l[i] - 1) - c - 1 - tmp);
			ans %= mod;
			tmp++;
		}
		cout << (fact[n] - ans + mod) % mod;
	}
	return 0;
}

