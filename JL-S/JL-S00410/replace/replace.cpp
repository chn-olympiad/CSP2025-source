#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5, M = 1e3 + 5, K = 5e6 + 5, bs = 29, mod = 1011451423;
vector <char> v1[N], v2[N];
vector <int> hsh1[N], hsh2[N], tp1, tp2;
int n, q, pw[K], vb1[N], vb2[N]; bool spe1 = 1;
inline void Init() {
    pw[0] = 1; for(int i = 1; i < K; ++ i) pw[i] = pw[i - 1] * bs % mod;
    for(int i = 1; i <= n; ++ i) {
        int len = v1[i].size();
        hsh1[i].emplace_back(v1[i][0] - 'a' + 1);
        hsh2[i].emplace_back(v2[i][0] - 'a' + 1);
        for(int j = 1; j < len; ++ j) {
            int u = hsh1[i].back() * bs % mod + v1[i][j] - 'a' + 1;
            int v = hsh2[i].back() * bs % mod + v2[i][j] - 'a' + 1;
            hsh1[i].emplace_back(u % mod), hsh2[i].emplace_back(v % mod);
            // cout << hsh1[i].back() << ' ' << hsh2[i].back() << '\n';
        }
        // cout << "------------\n";
    }
}
inline void check(string str) {
    int cntb = 0; if(!spe1) return ;
    for(int i = 0; i < (int)str.size(); ++ i) {
        if(str[i] != 'a' && str[i] != 'b') {spe1 = 0; return ;}
        if(str[i] == 'b') ++ cntb;
        if(cntb > 1) {spe1 = 0; return ;}
    }
}
inline void solve1(string str1, string str2) {
    int len = str1.size(), sr1 = 0, sr2 = 0;
    for(int i = 0; i < len; ++ i) {
        if(str1[i] == 'b') sr1 = i;
        if(str2[i] == 'b') sr2 = i;
    }
    int Anspe1 = 0;
    for(int i = 1; i <= n; ++ i) {
        int cur = v2[i].size();
        if(cur > len) continue;
        if((sr2 - sr1 == vb2[i] - vb1[i]) && (sr1 >= vb1[i] && sr2 >= vb2[i]) && (sr1 + cur - vb1[i] <= len && sr2 + cur - vb2[i] <= len)) ++ Anspe1; 
    }
    cout << Anspe1 << '\n';
}
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0); cin >> n >> q;
    for(int i = 1; i <= n; ++ i) {
        string str1, str2; cin >> str1 >> str2;
        check(str1), check(str2);
        for(int j = 0; j < (int)str1.size(); ++ j) v1[i].emplace_back(str1[j]);
        for(int j = 0; j < (int)str2.size(); ++ j) v2[i].emplace_back(str2[j]);
        if(spe1) {
            for(int j = 0; j < (int)v1[i].size(); ++ j) {
                if(v1[i][j] == 'b') vb1[i] = j;
                if(v2[i][j] == 'b') vb2[i] = j;
            }
        }
    }
    Init();
        for(int i = 1; i <= q; ++ i) {
            string str1, str2; cin >> str1 >> str2;
            check(str1), check(str2);
            if(str1.size() != str2.size()) {cout << 0 << '\n'; continue;}
            if(spe1) {solve1(str1, str2); continue;}
            tp1.clear(), tp2.clear(); int res = 0, len = str2.size();
            tp1.emplace_back(str1[0] - 'a' + 1);
            tp2.emplace_back(str2[0] - 'a' + 1);
            for(int j = 1; j < len; ++ j) {
                int u = tp1.back() * bs % mod + str1[j] - 'a' + 1;
                int v = tp2.back() * bs % mod + str2[j] - 'a' + 1;
                tp1.emplace_back(u % mod), tp2.emplace_back(v % mod);
            }
            for(int j = 1; j <= n; ++ j) {
                int cur = v2[j].size();
                if(len < cur) continue;
                for(int o = 0; o + cur - 1 < len; ++ o) {
                    int val0 = tp1[o + cur - 1]; if(o) val0 = (val0 - tp1[o - 1] * pw[cur] + mod) % mod;
                    int val1 = hsh1[j].back();
                    // cout << j << ',' << o << ":" << val0 << ' ' << val1 << '\n';
                    if(val0 == val1) {
                        int val2 = (tp1.back() - val1 * pw[len - cur - o] % mod + mod) % mod;
                        int val4 = hsh2[j].back() * pw[len - cur - o] % mod;
                        // cout << val2 << ' ' << val4 << '\n';
                        val2 = (val2 + val4 + mod) % mod;
                        int val3 = tp2.back();
                        // cout << val3 << "\n";
                        if(val3 == val2) ++ res;
                    }
                }
            }
            cout << res << '\n';
        }
    return 0;
}
// Ren5Jie4Di4Ling5%