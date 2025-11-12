#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N = 2e5+5;
namespace tianyu{
    int n, m, L1, L2;
    string s1[N], s2[N], t1[N], t2[N];
namespace L22{
    const ull P = 1e9+7, B = 131;
    map<pair<ull, ull>, int> cnt;
    ull get(const string &s){
        ull nw = 0;
        for (int i = 0;i < s.size();i++) nw = (nw * B + s[i]) % P;
        return nw;
    }
    void solve(){
        for (int i = 1;i <= n;i++){
            ull h1 = get(s1[i]), h2 = get(s2[i]);
            ++cnt[{h1, h2}];
        }
        for (int o = 1;o <= m;o++){
            if (t1[o].size() != t2[o].size()){
                cout << "0\n";
                continue;
            }
            int l = 0, r = t1[o].size() - 1;
            while (t1[o][l] == t2[o][l]) ++l;
            while (t1[o][r] == t2[o][r]) --r;
            int ans = 0;
            for (int i = 0;i <= l;i++){
                ull h1 = 0, h2 = 0;
                for (int j = i;j < t1[o].size();j++){
                    h1 = (h1 * B + t1[o][j]) % P;
                    h2 = (h2 * B + t2[o][j]) % P;
                    if (j >= r) ans += cnt[{h1, h2}];
                }
            }
            cout << ans << '\n';
        }
    }
}
namespace subB{
    int find(const string &s){
        for (int i = 0;i < s.size();i++){
            if (s[i] == 'b') return i;
        }
        return -1;
    }
    struct Q{
        int l, r, id;
        Q(int a, int b, int c) : l(a), r(b), id(c) {}
    };
    vector<pair<int, int>> a[N << 1];
    vector<Q> q[N << 1];
    map<int, int> Id;
    int ans[N];
    int tr[5000005];
    void add(int p){
        ++p;
        for (;p <= 5e6+1;p += p & -p) ++tr[p];
    }
    int query(int p){
        int res = 0;
        ++p;
        for (;p;p -= p & -p) res += tr[p];
        return res;
    }
    void clear(int p){
        ++p;
        for (;p <= 5e6+1;p += p & -p) tr[p] = 0;
    }
    void solve(){
        int now = 0;
        for (int i = 1;i <= n;i++){
            int x = find(s1[i]), y = find(s2[i]);
            int l = x, r = s1[i].size() - 1 - x;
            if (!Id[x - y + 5000000]) Id[x - y + 5000000] = ++now;
            a[Id[x - y + 5000000]].emplace_back(l, r);
        }
        for (int i = 1;i <= m;i++){
            if (t1[i].size() != t2[i].size()) continue;
            int x = find(t1[i]), y = find(t2[i]);
            int l = x, r = t1[i].size() - 1 - x;
            if (!Id[x - y + 5000000]) Id[x - y + 5000000] = ++now;
            q[Id[x - y + 5000000]].emplace_back(l, r, i);
        }
        for (int i = 1;i <= now;i++){
            if (!a[i].size() || !q[i].size()) continue;
            sort(a[i].begin(), a[i].end());
            sort(q[i].begin(), q[i].end(), [](Q x, Q y){return x.l < y.l;});
            for (int j = 0, k = 0;j < q[i].size();j++){
                while (k < a[i].size() && a[i][k].first <= q[i][j].l){
                    add(a[i][k].second);
                    ++k;
                }
                ans[q[i][j].id] = query(q[i][j].r);
            }
            for (int j = 0;j < a[i].size();j++){
                clear(a[i][j].second);
            }
        }
        for (int i = 1;i <= m;i++) cout << ans[i] << '\n';
    }
}
    void awa(){
        cin >> n >> m;
        for (int i = 1;i <= n;i++){
            cin >> s1[i] >> s2[i];
            L1 += s1[i].size() + s2[i].size();
        }
        for (int i = 1;i <= m;i++){
            cin >> t1[i] >> t2[i];
            L2 += t1[i].size() + t2[i].size();
        }
        if (L2 <= 2e3) return L22::solve();
        subB::solve();
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int T = 1;
    while (T--) tianyu::awa();
    return 0;
}
/*
hyw
he yi wei
?????????????
qwq
qwq
qwq
qwq
qwq
qwq
qwq
*/