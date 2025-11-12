#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
const int base = 131;
string s1[N], s2[N];
ll h1[N], h2[N], p[N];

ll query(ll *h, int l, int r) {
    return (h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i], s1[i] = "_" + s1[i], s2[i] = "_" + s2[i];
    for (int i = 1; i <= 1e5; i++) p[i] = p[i-1] * base % mod;
    for (int i = 1; i <= n; i++) {
        int len = s1[i].size()-1;
        for (int j = 1; j <= len; j++) h1[j] = (h1[j-1]*base+s1[i][j])%mod;
        for (int j = 1; j <= len; j++) h2[j] = (h2[j-1]*base+s2[i][j])%mod;
        mp[{h1[len], h2[len]}]++;
    }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int ans = 0, len = t1.size();
        t1 = "_" + t1, t2 = "_" + t2;
        for (int j = 1; j <= len; j++) h1[j] = (h1[j-1]*base+t1[j])%mod;
        for (int j = 1; j <= len; j++) h2[j] = (h2[j-1]*base+t2[j])%mod;
        for (int i = 1; i <= len; i++) {
            for (int j = i; j <= len; j++) {
                if (query(h1, 1, i-1) == query(h2, 1, i-1) && query(h1, j+1, len) == query(h2, j+1, len)) {
                    ans += mp[{query(h1, i, j), query(h2, i, j)}];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}