#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7, base = 331;
const int MAXN = 2e5 + 10;
map <pair<ll, ll>, int> ok;
ll ha[MAXN], hb[MAXN];
ll qpow(ll a, ll b){
	ll res = 1;
	while (b){
		if (b & 1){
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
ll calc(int l, int r, int o){
	if (r < l){
		return 0;
	}
	if (o == 1){
		return (ha[r] - qpow(base, r - l + 1) % MOD * ha[l - 1] % MOD + MOD) % MOD;
	}
	else{
		return (hb[r] - qpow(base, r - l + 1) % MOD * hb[l - 1] % MOD + MOD) % MOD;
	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		ll h1 = 0, h2 = 0;
		for (int i = 0; i < s1.size(); i++){
			h1 = (h1 * base + (s1[i] - 'a' + 1)) % MOD;
		}
		for (int i = 0; i < s2.size(); i++){
			h2 = (h2 * base + (s2[i] - 'a' + 1)) % MOD;
		}
		ok[{h1, h2}]++;
	}
	while (q--){
		string t1, t2;
		cin >> t1 >> t2;
		ll ans = 0;
		ha[0] = t1[0] - 'a' + 1;
		for (int i = 1; i < t1.size(); i++){
			ha[i] = (ha[i - 1] * base + (t1[i] - 'a' + 1)) % MOD;
		}
		hb[0] = t2[0] - 'a' + 1;
		for (int i = 1; i < t1.size(); i++){
			hb[i] = (hb[i - 1] * base + (t2[i] - 'a' + 1)) % MOD;
		}
		for (int l = 0; l < t1.size(); l++){
			for (int r = l; r < t1.size(); r++){
				if (ok[{calc(l, r, 1), calc(l, r, 2)}]){
					if (calc(0, l - 1, 1) == calc(0, l - 1, 2) && calc(r + 1, t1.size() - 1, 1) == calc(r + 1, t2.size() - 1, 2)){
						ans += ok[{calc(l, r, 1), calc(l, r, 2)}];
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}