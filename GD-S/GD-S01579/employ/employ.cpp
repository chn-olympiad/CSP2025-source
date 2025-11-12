#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using pll = pair<ll, ll>;
template<typename T1, typename T2> bool chkmin(T1 &a, const T2 &b) { return b < a ? (a = b, true) : false; }
template<typename T1, typename T2> bool chkmax(T1 &a, const T2 &b) { return b > a ? (a = b, true) : false; }
void fileIO(const string& x) { freopen((x + ".in").c_str(), "r", stdin); freopen((x + ".out").c_str(), "w", stdout); } 
mt19937_64 gen(random_device{}());
ll test_case = 1, test_num = 1;
const int int_Inf = 1e9; const ll Inf = 1e18;

const ll N = 20 + 5, Mod = 998244353;

ll n, m, s[N], c[N];
string str;

namespace brute {
//	bool check() {
//		for(int i = 1; i <= n; i++) if(s[i] != 1) return false;
//		return true;
//	}
	ll p[N];
	void solve() {
		ll ans = 0;
		for(int i = 1; i <= n; i++) p[i] = i;
		do {
			ll f_cnt = 0, s_cnt = 0;
			for(int i = 1; i <= n; i++) {
				if(s[i] == 1 && c[p[i]] > f_cnt) s_cnt++;
				else f_cnt++; 
			}
			if(s_cnt >= m) ans++;
		} while(next_permutation(p + 1, p + n + 1));
		ans = ans % Mod;
		cout << ans;
	}
}

void solution() {
	cin >> n >> m >> str;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) s[i + 1] = str[i] - '0';
	
	brute::solve();
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	fileIO("employ");
	
	solution();
	
	return 0;
}

