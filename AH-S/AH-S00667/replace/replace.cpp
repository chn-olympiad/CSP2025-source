#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

#define ll long long

const int N = 200005;
const int mod = 998244353;
const ll B = 31;

ll h[N], a[N], b[N];
unordered_map<int, vector<int> > mp;

ll H(string s) {
    ll res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = (res * B + s[i]) % mod;
        // res = (res + 31 * (s[i] * 3 - ((i == s.size() - 1) ? 0 : s[i + 1]))) % mod;
    }
    return res;
}

int main() {
    // system("diff replace.out replace3.ans");
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        h[i] = (H(s2) + mod - H(s1) + s2[s2.size() - 1] * 1331) % mod;
        mp[h[i]].push_back(s1.size());
        // printf("have:%lld\n", h[i]);
    }
    for (auto &x : mp) {
        auto &v = x.second;
        sort(v.begin(), v.end());
        // printf("%d\n", x.first);
    }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        for (int i = 0; i < t1.size(); i++) {
            a[i] = ((i == 0 ? 0 : a[i - 1]) * B + t1[i]) % mod;
            // a[i] == (a[i] + 31 * (t1[i] * 3 - ((i == t1.size() - 1) ? 0 : t1[i - 1])));
        }
        for (int i = 0; i < t2.size(); i++) {
            b[i] = ((i == 0 ? 0 : b[i - 1]) * B + t2[i]) % mod;
            // b[i] == (b[i] + 31 * (t2[i] * 3 - ((i == 0) ? 0 : t2[i - 1])));
        }
        // printf("DDD: %d\n", b[t2.size() - 1]);
        ll ans = 0;
        for (int i = t1.size() - 1; i >= 0; i--) {
            int need = (b[i] - a[i] + t2[i] * 1331 + mod) % mod;
            auto &x = mp[need];
            ans += upper_bound(x.begin(), x.end(), i + 1) - x.begin();
            // printf("NEED:: %d\n",(b[i] - a[i] + t2[i] * 1331 + mod) % mod);
            if (t1[i] != t2[i]) break;
        }
        // printf("E~~~~~~~~~~~~~~~~~\n");
        cout << ans << '\n';
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbaa

*/