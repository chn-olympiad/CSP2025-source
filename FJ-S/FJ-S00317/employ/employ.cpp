#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 510;
const ll mod = 998244353;
int n, m, c[N], cnt[N];
vector<int> p;
string s;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m >> s, s = " " + s;
	int Max = 0;
	for (int i = 1; i <= n; i++) cin >> c[i], Max = max(Max, c[i]), cnt[c[i]]++;
	cnt[Max + 1] = 0;
	for (int i = Max; i >= 0; i--) cnt[i] += cnt[i + 1];
	for (int i = 1; i <= n; i++)
		if (s[i] == '1') p.push_back(i);
	int len = p.size();
	if (len < m) {
		cout << "0\n";
		return 0; 
	}
	ll ans = 0;
	for (int i = (1 << m) - 1; i <= (1 << len) - 1; i++) {
		int res = 0;
		vector<int> tmp;
		for (int j = 0; j < len; j++)
			if ((i >> j) & 1) res++, tmp.push_back(p[j]);
		if (res < m) continue;
		ll ret = 1, t = 0;
		for (int j = 0; j < (int)tmp.size(); j++) {
			int k = tmp[j] - 1 - j;
			tmp[j] = cnt[k + 1];  
		}
		for (int j = (int)tmp.size() - 1; j >= 0; j--) ret = ret * max(0ll, 1ll * tmp[j] - (t++)) % mod;
		ans = (ans + ret) % mod;
	}
	cout << (ans % mod + mod) % mod << "\n";
	return 0;
}

