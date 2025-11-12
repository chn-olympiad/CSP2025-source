#include <bits/stdc++.h>
using std::cin;

namespace solution {
    using u64 = unsigned long long;
    const int L = 5e6 + 5, N = 2e5 + 5;
    const u64 base = 93;
    std::string s[N][2];
    int n, q;
    u64 calc_hash(const std::string& s){
        u64 ret = 0;
        for(char c : s) ret = ret * base + (c - 'a' + 1);
        return ret;
    }
    std::string puck[N][2];
    u64 pre[L], suf[L], lft[N], mid[N], mid2[N], rgt[N], l[N], r[N];
    bool flag[N];
    bool good(std::string s){
        return std::count(s.begin(), s.end(), 'b') == 1 && std::count(s.begin(), s.end(), 'a') == s.size() - 1;
    }
    struct sweepline {
        std::vector<int> upd;
        std::vector<std::pair<int, int>> qry;
    };
    std::map<std::pair<u64, u64>, std::map<int, sweepline>> mp;
    struct BIT {
        int t[L];
        void update(int p, int v){
            p++; while(p < L) t[p] += v, p += p & -p;
        }
        int query(int p){
            int ans = 0;
            p++; while(p) ans += t[p], p -= p & -p;
            return ans;
        }
    } T;
    int answer[N];
    void solve(){
        cin >> n >> q; bool test = true;
        for(int i=1;i<=n;i++){
            cin >> s[i][0] >> s[i][1]; test &= (good(s[i][0]) & good(s[i][1]));
            l[i] = 0, r[i] = s[i][0].size();
            if(s[i][0] == s[i][1]){ flag[i] = 1; continue; }
            for(;s[i][0][l[i]]==s[i][1][l[i]];l[i]++);
            for(;s[i][0][r[i]]==s[i][1][r[i]];r[i]--);
            std::string p = s[i][0].substr(0, l[i]); std::reverse(p.begin(), p.end());
            lft[i] = calc_hash(p);
            mid[i] = calc_hash(s[i][0].substr(l[i], r[i] - l[i] + 1));
            mid2[i] = calc_hash(s[i][1].substr(l[i], r[i] - l[i] + 1));
            rgt[i] = calc_hash(s[i][0].substr(r[i] + 1));
        }
        for(int i=1;i<=q;i++) cin >> puck[i][0] >> puck[i][1], test &= good(puck[i][0]) & good(puck[i][1]);
        if(test){
            for(int i=1;i<=q;i++){
                std::string t[2] = {std::move(puck[i][0]), std::move(puck[i][1])};
                if(t[0].size() != t[1].size()){
                    std::cout << "0\n";
                    continue;
                }
                int L = 0, R = t[0].size() - 1;
                for(;t[0][L]==t[1][L];L++);
                for(;t[0][R]==t[1][R];R--);
                u64 dif1 = calc_hash(t[0].substr(L, R - L + 1)), dif2 = calc_hash(t[1].substr(L, R - L + 1));
                mp[{dif1, dif2}][L].qry.emplace_back(t[0].size() - R, i);
            }
            for(int i=1;i<=n;i++) mp[{mid[i], mid2[i]}][l[i]].upd.push_back(s[i][0].size() - r[i]);
            for(auto& [_, _mp] : mp){
                for(auto& [__, swl] : _mp){
                    for(int x : swl.upd) T.update(x, 1);
                    for(auto [x, id] : swl.qry) answer[id] = T.query(x);
                }
                for(auto& [_, swl] : _mp) for(int x : swl.upd) T.update(x, -1);
            }
            for(int i=1;i<=q;i++) std::cout << answer[i] << '\n';
            return;
        }
        for(int i=1;i<=q;i++){
            std::string t[2] = {std::move(puck[i][0]), std::move(puck[i][1])};
            if(t[0].size() != t[1].size()){
                std::cout << "0\n";
                continue;
            }
            int L = 0, R = t[0].size() - 1;
            for(;t[0][L]==t[1][L];L++);
            for(;t[0][R]==t[1][R];R--);
            pre[L] = suf[R] = 0;
            for(int i=R+1;i<t[0].size();i++) suf[i] = suf[i - 1] * base + (t[0][i] - 'a' + 1);
            for(int i=L-1;~i;i--) pre[i] = pre[i + 1] * base + (t[0][i] - 'a' + 1);
            u64 dif1 = calc_hash(t[0].substr(L, R - L + 1)), dif2 = calc_hash(t[1].substr(L, R - L + 1));
            int ans = 0;
            for(int i=1;i<=n;i++){
                if(flag[i]) continue;
                if(mid[i] != dif1 || mid2[i] != dif2) continue;
                if(l[i] > L || (R + (s[i][0].size() - r[i] - 1) > t[0].size())) continue;
                if(pre[L - l[i]] != lft[i] || suf[R + (s[i][0].size() - r[i] - 1)] != rgt[i]) continue;
                ans++;
            }
            std::cout << ans << '\n';
        }
    }
}

signed main(){
    #ifndef LOCAL
    std::freopen("replace.in", "r", stdin);
    std::freopen("replace.out", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    solution::solve();
    return 0;
}

// think twice, code once
// Writting by xiezheyuan
