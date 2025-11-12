#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 510, P = 998244353;
string s, t;
ll n, m;
array<ll, N> c, d, tot, p;

void init_data() {
	cin >> n >> m >> s;
	for(ll i = 1; i <= n; i++) {
		cin >> c[i];
		p[i] = i;
	}
	sort(c.begin() + 1, c.begin() + n + 1);
}

void dyna_prog() {
	do {
		t = s;
		ll cnt = 0;
		for(ll i = 1; i <= n; i++) {
			ll cnt1 = 0;
			for(ll j = 1; j < i; j++) {
				if(t[j - 1] == '0') {
					cnt1++;
				}
			}
			if(cnt1 < c[p[i]] && t[i - 1] != '0') {
				cnt++;
			} else {
				t[i - 1] = '0';
			}
		}
		tot[cnt]++;
	} while(next_permutation(p.begin() + 1, p.begin() + n + 1));
}

ll get_ans() {
	ll ans = 0;
	for(ll i = m; i <= n; i++) {
		ans += tot[i];
	}
	return ans;
}

int main() {
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	init_data(), dyna_prog();
	cout << get_ans() << '\n';
}
