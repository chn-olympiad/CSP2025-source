#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5+5, M = 5e6+5;
const ull base = 13331;
ull hsh(const string& str) {
    ull ans = 0;
    for (char c : str)
        ans = ans*base+c-'a';
    return ans;
}
struct Hash {
    ull h[2005], pw[2005];
    int sz;
    Hash(const string& str) {
        sz = str.size()-1;
        ull ans = 0;
        pw[0] = 1;
        h[0] = str[0]-'a';
        for (int i = 1; i < str.size(); i++) {
            pw[i] = pw[i-1]*base;
            h[i] = h[i-1]*base+str[i]-'a';
        }
    }
    ull sub(int l, int r) {
        if (l > r) return 0;
        if (l == 0) return h[r];
        return h[r]-pw[r-l+1]*h[l-1];
    }
    ull rep(int l, int r, ull str) {
        return sub(r+1, sz)+pw[sz-r]*str+pw[sz-l+1]*sub(0, l-1);
    }
};
string s[N][2], t[N][2];
int n, q, L1, L2;

namespace Solve1 {
unordered_map<ull, vector<ull>> ms;
unordered_map<ull, int> sz;

void work() {
    for (int i = 1; i <= n; i++) {
        ull s0 = hsh(s[i][0]), s1 = hsh(s[i][1]);
        ms[s0].push_back(s1);
        sz[s0] = s[i][0].size(), sz[s1] = s[i][1].size();
    }
    for (int _ = 1; _ <= q; _++) {
        Hash t1(t[_][0]), t2(t[_][1]);
        int ans = 0;
        if (t1.sz != t2.sz) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 0; i < t[_][0].size(); i++) {
            for (const auto& pr : ms) {
                auto s1 = pr.first;
                auto s2s = pr.second;
                if (i+sz[s1] > t[_][0].size()) continue;
                if (t1.sub(i, i+sz[s1]-1) != s1) continue;
                for (const auto& s2 : s2s) {
                    if (t1.rep(i, i+sz[s1]-1, s2) == t2.h[t2.sz])
                        ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}
}

namespace SolveB {
unordered_map<int, map<int, vector<int>>> db;

void work() {
    for (int i = 1; i <= n; i++) {
        int j1, j2;
        for (int j = 0; j < s[i][0].size(); j++)
            if (s[i][0][j] == 'b') {
                j1 = j;
                break;
            }
        for (int j = 0; j < s[i][1].size(); j++)
            if (s[i][1][j] == 'b') {
                j2 = j;
                break;
            }
        db[j2-j1][j1].push_back(s[i][0].size()-j1);
    }
    for (auto& [k1, v1] : db)
        for (auto& [k2, v2] : v1)
            sort(v2.begin(), v2.end());
    for (int i = 1; i <= q; i++) {
        int j1, j2, ans = 0;
        for (int j = 0; j < t[i][0].size(); j++)
            if (t[i][0][j] == 'b') {
                j1 = j;
                break;
            }
        for (int j = 0; j < t[i][1].size(); j++)
            if (t[i][1][j] == 'b') {
                j2 = j;
                break;
            }
        for (auto& [k1, v1] : db[j2-j1]) {
            if (k1 > j1) break;
            ans += upper_bound(v1.begin(), v1.end(), t[i][0].size()-j1)-v1.begin();
        }
        cout << ans << '\n';
    }
}
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> s[i][0] >> s[i][1], L1 += s[i][0].size()+s[i][1].size();
    for (int i = 1; i <= q; i++)
        cin >> t[i][0] >> t[i][1], L2 += t[i][0].size()+t[i][1].size();
    if (L1 <= 2000 && L2 <= 2000)
        Solve1::work();
    else
        SolveB::work();
    return 0;
}