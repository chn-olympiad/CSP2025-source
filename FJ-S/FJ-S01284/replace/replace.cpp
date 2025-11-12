/*

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n, q, pw[5000002], hs[2][200002];
string s[2][200002], t[2];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	pw[0] = 0;
	for (ll i = 1; i <= 5000000; i ++ ) pw[i] = pw[i - 1] * 114514 % mod;
	for (ll i = 1; i <= n; i ++ ) {
		cin >> s[0][i];
		ll hs1 = 0;
		for (ll j = 0; j < s[0][i].size(); j ++ ) hs1 = (hs1 * 114514 + (s[0][i][j] - 'a')) % mod;
		cin >> s[1][i];
		ll hs2 = 0;
		for (ll j = 0; j < s[1][i].size(); j ++ ) hs2 = (hs2 * 114514 + (s[1][i][j] - 'a')) % mod;
		hs[0][i] = hs1, hs[0][i] = hs2;
	}
	for (ll i = 1; i <= q; i ++ ) {
		cin >> t1 >> t2;
		
		
	}
