#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 2e5 + 10, M = 1e7 + 10;
ll n, q, l, r;
array<array<string, 3>, N> s;
array<ll, M> pi1, pi2;

void init_data() {
	cin >> n >> q;
	for(ll i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}
}

void buildpi(string str, array<ll, M> &pi) {
	pi[0] = 0;
	for(ll i = 1, j = 0; i < str.size(); i++) {
		while(j && str[j] != str[i]) {
			j = pi[j - 1];
		}
		pi[i] = str[j] != str[i] ? 0 : ++j;
	}
}


ll solve() {
	string t1, t2;
	cin >> t1 >> t2;
	if(t1.size() != t2.size()) {
		return 0;
	}
	ll res = 0;
	string tmp1, tmp2;
	for(l = 0; l < n; l++) {
		if(t1[l] != t2[l]) {
			break;
		}
	}
	for(r = n - 1; ~r; r--) {
		if(t1[r] != t2[r]) {
			break;
		}
	}
	for(ll i = 1; i <= n; i++) {
		tmp1 = s[i][1] + '#' + t1, tmp2 = s[i][2] + '#' + t2;
		buildpi(tmp1, pi1);
		buildpi(tmp2, pi2);
		for(ll j = s[i][1].size() + r + 1; j < tmp1.size() && j - s[i][1].size() + 1 <= s[i][1].size() + l + 1; j++) {
			if(pi1[j] == s[i][1].size() && pi2[j] == s[i][2].size()) {
				res++;
				break;
			}
		}
	}
	return res;
}

int main() {
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	init_data();
	while(q--) {
		cout << solve() << '\n';
	}
}
