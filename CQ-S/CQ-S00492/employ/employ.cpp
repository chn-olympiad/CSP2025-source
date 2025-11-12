#include <bits/stdc++.h>
#define ll long long
#define db double
#define ull unsigned long long
#define uint unsigned int

#define endl "\n"
#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()

#define pii pair<int, int>
#define pll pair<ll, ll>

// #define x first
// #define y second

using namespace std;

const int inf = 2e9;
const ll INF = 2e18;
const int mod = 998244353;
const db eps = 1e-6;
const int maxn = 1e5 + 5;
const int N = 1e7 + 7;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    s = " " + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
//    cout << n << ' ' << m << endl;

    ll ans = 0;
    vector<int> vis(n + 1, 0);
    auto dfs = [&](auto &&self, int tot, int cnt) -> void {
//    	cout << tot << ' ' << cnt << endl;
        if (tot == n) {
//            cout << cnt << endl;
            if (n - cnt >= m) ans = (ans + 1) % mod;
            return;
        }
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            vis[i] = 1;
            if (((s[tot + 1] - '0') == 0) || cnt >= a[i]) self(self, tot + 1, cnt + 1);
            else self(self, tot + 1, cnt);
            vis[i] = 0;
        }
    } ;
    dfs(dfs, 0, 0);
    cout << ans << endl;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

/*
10 5 
1101111011 
6 0 4 2 1 2 5 4 3 3 
*/


