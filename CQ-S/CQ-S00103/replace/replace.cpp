#include<bits/stdc++.h>
#define ll long long
#define pii pair<int , int>
using namespace std;
const int MAXN = 5e5 + 5 , MOD = 1e9 + 7;
int n , q , idx , lpos[MAXN] , rpos[MAXN] , len[MAXN];
ll all1[MAXN] , all2[MAXN] , fac[5000001];
vector<int> E[MAXN] , G[MAXN];
unordered_map<ll , int> mp1 , mp2;
string s , t;
int main() {
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr) , cout.tie(nullptr);
	fac[0] = 1;
	for (int i = 1 ; i <= 5000000 ; i ++) fac[i] = fac[i - 1] * 13331 % MOD;
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i = -~i) {
		cin >> s >> t;
		int l = s.length();
		len[i] = l;
		lpos[i] = -1 , rpos[i] = l;
		for (int j = 0 ; j < l ; j = -~j) {
			if (s[j] != t[j]) {
				lpos[i] = j;
				break;
			}
		}
		if (lpos[i] == -1) continue;
		for (int j = l - 1 ; ~j ; -- j) {
			if (s[j] != t[j]) {
				rpos[i] = j;
				break;
			}
		}
		ll has = 0;
		for (int j = lpos[i] ; j <= rpos[i] ; j = -~j) has = (has * 13331 + s[j]) % MOD;
		if (!mp1.count(has)) mp1[has] = ++ idx;
		E[mp1[has]].push_back(i);
		has = 0;
		for (int j = lpos[i] ; j <= rpos[i] ; j = -~j) has = (has * 13331 + t[j]) % MOD;
		if (!mp2.count(has)) mp2[has] = ++ idx;
		G[mp2[has]].push_back(i);
		for (int j = 0 ; j < l ; j = -~j) all1[i] = (all1[i] * 13331 + s[j]) % MOD , all2[i] = (all2[i] * 13331 + t[j]) % MOD;
	}
	for (int i = 1 ; i <= q ; i = -~i) {
		cin >> s >> t;
		int l = s.length();
		int ql = 0 , qr = 0;
		for (int j = 0 ; j < l ; j = -~j) {
			if (s[j] != t[j]) {
				ql = j;
				break;
			}
		}
		for (int j = l - 1 ; ~j ; -- j) {
			if (s[j] != t[j]) {
				qr = j;
				break;
			}
		}
		vector<ll> has1 , has2;
		has1.push_back(0) , has2.push_back(0);
		for (int j = 0 ; j < l ; j ++) has1.push_back((has1.back() * 13331 + s[j]) % MOD);
		for (int j = 0 ; j < l ; j ++) has2.push_back((has2.back() * 13331 + t[j]) % MOD);
		ll sb1 = 0 , sb2 = 0;
		for (int j = ql ; j <= qr ; j = -~j) {
			sb1 = (sb1 * 13331 + s[j]) % MOD;
			sb2 = (sb2 * 13331 + t[j]) % MOD;
		}
		if (!mp1.count(sb1) || !mp2.count(sb2)) {
			cout << 0 << '\n';
			continue;
		}
		sb1 = mp1[sb1] , sb2 = mp2[sb2];
		int sum = 0;
		if (E[sb1].size() < G[sb2].size()) {
			for (int j : E[sb1]) {
				if (len[j] > l) continue;
				int llen = lpos[j] , rlen = len[j] - rpos[j] - 1;
				llen = ql - llen , rlen = qr + rlen; llen ++ , rlen ++;
				if (llen < 1 || rlen > l) continue;
				ll nowhas = (has1[rlen] - has1[llen - 1] * fac[rlen - llen + 1] % MOD + MOD) % MOD;
				if (nowhas != all1[j]) continue;
				nowhas = (has2[rlen] - has2[llen - 1] * fac[rlen - llen + 1] % MOD + MOD) % MOD;
				if (nowhas != all2[j]) continue;
				sum ++;
			}
		} else {
			for (int j : G[sb2]) {
				if (len[j] > l) continue;
				int llen = lpos[j] , rlen = len[j] - rpos[j] - 1;
				llen = ql - llen , rlen = qr + rlen; llen ++ , rlen ++;
				if (llen < 1 || rlen > l) continue;
				ll nowhas = (has1[rlen] - has1[llen - 1] * fac[rlen - llen + 1] % MOD + MOD) % MOD;
				if (nowhas != all1[j]) continue;
				nowhas = (has2[rlen] - has2[llen - 1] * fac[rlen - llen + 1] % MOD + MOD) % MOD;
				if (nowhas != all2[j]) continue;
				sum ++;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
