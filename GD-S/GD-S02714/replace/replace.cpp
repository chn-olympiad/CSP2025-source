#include <bits/stdc++.h>
using namespace std;

namespace IMC {
    typedef unsigned long long ull;
    constexpr int N = 2e5 + 3;
    constexpr ull MOD = 1e9 + 7, base = 131;
    ull h[2][N*13], p[N*13];
    map<pair<ull,ull>, int> mp;
    int n, q, lens[N], tp;
    bitset<N*13> vis;
    string s1,s2;
    bool special = true;
    int mxr, ans[N];
    struct Node {
        int type, L, R, id;
        Node(int _t, int _l, int _r, int _id) : type(_t), L(_l), R(_r), id(_id) {}
        bool operator<(const Node &p) const {
            return L != p.L ? L < p.L : type < p.type;
        }
    };
    int bit[N];
    void add(int x, int y) {
        // cerr << "ADD: " << x << ' ' << y << '\n';
        for (;x<=mxr+1;x+=x&(-x)) bit[x] += y;
    }
    int qry(int x) {
        int res = 0;
        for (;x;x-=x&(-x)) res += bit[x];
        return res;
    }
    unordered_map<string,vector<Node> > mp2;
    ull calc(const string &s) {
        int as = (s[0] == 'a'), bs = (s[0] == 'b');
        ull hs = s[0] - 'a' + 1;
        for (int i = 1; i < s.size(); ++i) {
            hs = (hs * base + s[i] - 'a' + 1) % MOD;
            as += (s[i] == 'a'); bs += (s[i] == 'b');
        }
        if (as + bs != s.size() || bs != 1) special = false;
        return hs;    
    }
    void calc(int id, const string &s) {
        h[id][0] = s[0] - 'a' + 1;
        for (int i = 1; i < s.size(); ++i)
            h[id][i] = (h[id][i-1] * base % MOD + s[i] - 'a' + 1) % MOD;  
    }
    ull getHash(int id, int l, int r) {
        if (l == 0) return h[id][r];
        return (h[id][r] - h[id][l-1] * p[r-l+1] % MOD + MOD) % MOD;
    }
    void main() {
        p[0] = 1;
        for (int i = 1; i <= 2500000; ++i) p[i] = p[i-1] * base % MOD;
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> s1 >> s2;
            mp[{calc(s1), calc(s2)}]++;
            if (!vis[s1.size()])
                lens[++tp] = s1.size(), vis.set(s1.size());

            int m = s1.size();
            int L = 0, R = 0;
            for (;L<s1.size();++L) if (s1[L] != s2[L]) break;
            for (;R<s1.size();++R) if (s1[m-R-1] != s2[m-R-1]) break;
            if (L == s1.size()) continue;
            mxr = max(mxr, R);
            mp2[s1.substr(L, m - L - R) + 'A' + s2.substr(L, m - L - R)].push_back(Node(0,L,R,0));
        }
        sort(lens+1,lens+1+tp);
        for (int i = 1; i <= q; ++i) {
            cin >> s1 >> s2;
            if (s1.size() != s2.size()) continue;
            bool spe = true;
            int as = 0, bs = 0;
            for (int j = 0; j < s1.size(); ++j) {
                as += (s1[j] == 'a');
                bs += (s1[j] == 'b');
            }
            if (as + bs != s1.size() || bs != 1) spe = false;
            if (spe) {
                int as = 0, bs = 0;
                for (int j = 0; j < s1.size(); ++j) {
                    as += (s2[j] == 'a');
                    bs += (s2[j] == 'b');
                }
                if (as + bs != s1.size() || bs != 1) spe = false;
            }
            if (spe) {
                int m = s1.size();
                int L = 0, R = 0;
                for (;L<s1.size();++L) if (s1[L] != s2[L]) break;
                for (;R<s1.size();++R) if (s1[m-R-1] != s2[m-R-1]) break;
                mxr = max(mxr, R);
                mp2[s1.substr(L, m - L - R) + 'A' + s2.substr(L, m - L - R)].push_back(Node(1,L,R,i));
                continue;
            }
            int m = s1.size();
            int L = 0, R = m-1;
            for (;L<s1.size();++L) if (s1[L] != s2[L]) break;
            for (;R;--R) if (s1[R] != s2[R]) break;
            calc(0,s1); calc(1,s2);
            int ptr = lower_bound(lens+1,lens+1+tp,R-L+1) - lens;
            for (;ptr<=tp;++ptr) {
                int len = lens[ptr];
                for (int r = max(R, len-1); r <= min(m - 1, len + L - 1); ++r) {
                    auto pai = make_pair(getHash(0,r-len+1,r), getHash(1,r-len+1,r));
                    if (mp.find(pai) != mp.end())
                        ans[i] += mp[pai];
                }
            }
        }
        for (auto pe : mp2) {
            auto vec = pe.second;
            sort(vec.begin(),vec.end());
            for (auto e : vec) {
                if (e.type == 0) add(e.R + 1, 1);
                if (e.type == 1) ans[e.id] = qry(e.R + 1);
            }
            for (auto e : vec) if (e.type == 0) add(e.R + 1, -1);
        }
        for (int i = 1; i <= q; ++i)
            cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    IMC::main();
    return 0;
}