#include<bits/stdc++.h>
using namespace std;
typedef long long ll, i64;
typedef double db;
const int N = 1e4 + 5;
const long long MOD = 998244353;

ll max(ll a, ll b) {
	if (a > b) return a;
	return b;
}

ll min(ll a, ll b) {
	if (a < b) return a;
	return b;
}

ll cmp_d(ll a, ll b) {
	return a > b;
}

ll n, m, c[505], t[505], rest[505], ans, k[505];//rest£ºÊ£Óà  
bool pass[505] = {1};
string s;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	ll cnt_0 = 0;
	for (int i = 0; i < s.size(); i++) {
		pass[i + 1] = s[i] - '0';
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (!c[i]) cnt_0++;
		t[c[i]]++;
	}
	rest[0] = n - t[0];
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		rest[i] = rest[i - 1];
		if (pass[i - 1]) continue;
		cnt++;
		rest[i] -= t[cnt];
	}
	cnt = 0;// the chosen ones
	for (int i = n; i >= 1; i--) {
		k[i] = rest[i] - cnt;
		//cout << "k[" << i << "] = " << rest[i] << " - " << cnt << " = " << k[i] << "\n";
		if (rest[i] > cnt) {
			cnt++;
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << k[i];
//	}
	
	bool is_A = 1;
	for (int i = 1; i <= n; i++) {
		if (pass[i] != 1) is_A = 0;
	}
	
	if (is_A) {
		ans = 1;
		for (int i = 1; i <= n; i++) {
			if (k[i] != 0) {
				ans *= k[i];
			}
			ans %= MOD;
		}
	}
	
	cout << ans;
	
	return 0;
}
