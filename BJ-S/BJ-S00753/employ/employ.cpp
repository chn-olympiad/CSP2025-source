#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 110;
const ll mod = 998244353;

int n, m, c[N];
string s;
vector<int> a;
bool st[N];
ll ans;

int check() {
	int cnt = 0, employ = 0;
	for (int i =0; i < a.size(); i++) {
		if (cnt >= c[a[i]]) {
            cnt++;
            continue;
		}
		if (s[i] == '1') employ++;
		else cnt++;
	}
	if (employ < m) return 0;
	return 1;
}

void dfs(int u) {
	if (u == n) {
		ans += check();
		ans %= mod;
		a.clear();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (st[i] == false) {
			a.push_back(i);
			st[i] = true;
			dfs(u + 1);
			st[i] = false;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m >> s;
	int t = 0;
	for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (c[i] == 0) t++;
	}

	bool tag = true;
	for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            tag = false;
            break;
        }
	}

	if (tag) {
        if (n - t >= m) {
            ll res = 1;
            for (ll i = 2; i <= n; i++) {
                res *= i;
                res %= mod;
            }
            cout << res << "\n";
        } else {
            cout << 0 << "\n";
        }
        return 0;
	}

	dfs(0);
	cout << ans << "\n";



	return 0;
}
