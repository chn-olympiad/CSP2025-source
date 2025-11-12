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
const ll mod = 1e9 + 7;
const ll base = 233;
const db eps = 1e-6;
const int maxn = 5e6 + 5;
const int N = 1e7 + 7;

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> poww(maxn + 5);
    poww[0] = 1;
    for (int i = 1; i <= n; i++) poww[i] = poww[i - 1] * base % mod;
//    ll h1[maxn], h2[maxn];
    vector<ll> h1(maxn, 0), h2(maxn, 0);
    unordered_map<ll, unordered_map<ll, ll>> mp;
    for (int i = 1; i <= n; i++) {
        string s1, s2; cin >> s1 >> s2;
        int l = s1.size();
        s1 = " " + s1, s2 = " " + s2;
        h1.clear(); h2.clear();
        h1.resize(l + 1, 0); h2.resize(l + 1, 0);
        for (int j = 1; j <= l; j++) h1[j] = (h1[j - 1] + s1[j]) * base % mod;
        for (int j = 1; j <= l; j++) h2[j] = (h2[j - 1] + s2[j]) * base % mod;

//		cout << i << ' ' << h1[l] << ' ' << h2[l] << endl;
        mp[h1[l]][h2[l]] += 1;
    }

    auto get = [&](vector<ll> &h, int r, int l) -> ll {
        if (l > r) return 0;
        return (h[r] - h[l - 1] * poww[r - l + 1] % mod + mod) % mod;
    } ;

    while (q--) {
        string t1, t2; cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        int l = t1.size();
        t1 = " " + t1, t2 = " " + t2;
        h1.clear(); h2.clear();
        h1.resize(l + 1, 0); h2.resize(l + 1, 0);
        for (int j = 1; j <= l; j++) h1[j] = (h1[j - 1] + t1[j]) * base % mod;
        for (int j = 1; j <= l; j++) h2[j] = (h2[j - 1] + t2[j]) * base % mod;
        
//        for (int i = 1; i <= l; i++) cout << h1[i] << ' ';
//        cout << endl;
//        for (int i = 1; i <= l; i++) cout << h2[i] << ' ';
//        cout << endl;

        int L = 1, R = l, minn = 0;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (get(h1, l, mid) != get(h2, l, mid)) L = mid + 1, minn = mid;
            else R = mid - 1;
        }
//        minn -= 1;

        int maxx = 0;
        L = 1, R = l;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (get(h1, mid, 1) != get(h2, mid, 1)) R = mid - 1, maxx = mid;
            else L = mid + 1; 
        }
//        maxx += 1;

        for (int i = max(1, minn); i <= l; i++) {
//            if (get(h1, l, i + 1) != get(h2, l, i + 1)) continue;
            for (int j = min(i, maxx); j >= 1; j--) {
            	ll u = get(h1, i, j), v = get(h2, i, j);
//            	cout << i << ' ' << j << ' ' << u << ' ' << v << ' ' << get(h1, j - 1, 1) << ' ' << get(h2, j - 1, 1) << endl;
//            	cerr << mp[u][v] << ' ' << mp.count(u) << ' ' << mp[u].count(v) << endl;
//                if (get(h1, j - 1, 1) == get(h2, j - 1, 1)) {
//                	cout << "YES" << endl;
                	if (mp.count(u)) if (mp[u].count(v)) ans += mp[u][v];
//				}
            }
        }

        cout << ans << endl;
    }
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
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
3 4 
a b 
b c 
c d 
aa bb 
aa b 
a c 
b a 

*/
