#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5, MAXM = 5e6 + 5, mod = 998244353;
int n, q, st[MAXN], ed[MAXN], st1[MAXN], ed1[MAXN]; ll ans[MAXN];
string S[MAXN], T[MAXN], t1[MAXN], t2[MAXN];
map<int, vector<int>> mp, que;

struct Tr{
    int tot, tr[MAXN][26], cnt[MAXN];
    vector<int> vec[MAXN], que[MAXN];
    void clear(){
        for(int i = 1; i <= tot; ++i) for(int j = 0; j < 26; ++j) tr[i][j] = 0;
        for(int i = 1; i <= tot; ++i) cnt[i] = 0, vec[i].clear(), que[i].clear(); tot = 1;
    }
    void insert(string s, int v, int idx, int oo){
        int u = 1;
        for(auto c : s){
            int o = c - 'a';
            if(!tr[u][o]) tr[u][o] = ++tot;
            u = tr[u][o];
        }
        cnt[u] += v; if(oo) vec[u].push_back(idx);
    }
    void get(string s, int idx){
        int u = 1;
        for(auto c : s){
            int o = c - 'a';
            if(!tr[u][o]) break;
            u = tr[u][o];
        }
        que[u].push_back(idx);
    }
    ll query(string s){
        int u = 1; ll res = cnt[1];
        for(auto c : s){
            int o = c - 'a';
            if(!tr[u][o]) break;
            u = tr[u][o]; res += cnt[u];
        }
        return res;
    }
}Tr, T1;

void dfs(int u){
    for(int i : Tr.vec[u]){
        string s = ""; for(int j = ed[i]; j < S[i].size(); ++j) s += S[i][j];
        T1.insert(s, 1, 0, 0);
    }
    for(int i : Tr.que[u]){
        string s = ""; for(int j = ed1[i]; j < t1[i].size(); ++j) s += t1[i][j];
        ans[i] = T1.query(s);
    }
    for(int i = 0; i < 26; ++i){
        if(Tr.tr[u][i]) dfs(Tr.tr[u][i]);
    }
    for(int i : Tr.vec[u]){
        string s = ""; for(int j = ed[i]; j < S[i].size(); ++j) s += S[i][j];
        T1.insert(s, -1, 0, 0);
    }
}

namespace sub1{
    vector<int> nxt[2][MAXN]; bool vis[MAXM];
    void solve(){
        for(int i = 1; i <= n; ++i){
            S[i] = " " + S[i], T[i] = " " + T[i];
            for(int o : {0, 1}) nxt[o][i].resize(S[i].size() + 2);
            int siz = S[i].size();
            int I = i;
            for(int i = 2, j = 0; i < siz; ++i){
                while(j && S[I][j + 1] != S[I][i]) j = nxt[0][I][j];
                if(S[I][j + 1] == S[I][i]) j++;
                nxt[0][I][i] = j;
            }
            for(int i = 2, j = 0; i < siz; ++i){
                while(j && T[I][j + 1] != T[I][i]) j = nxt[1][I][j];
                if(T[I][j + 1] == T[I][i]) j++;
                nxt[1][I][i] = j;
            }
        }
        for(int _ = 1; _ <= q; ++_){
            // cin >> t1 >> t2;
            string t1 = ::t1[_], t2 = ::t2[_];
            t1 = " " + t1, t2 = " " + t2;
            int siz = t1.size(), ans = 0;
            int st = -1, ed = -1;
            for(int j = 1; j < siz; ++j){
                if(t1[j] != t2[j]){
                    if(!~st) st = j; ed = j;
                }
            }
            // cout << "st: " << st << ' ' << ed << '\n';
            for(int t = 1; t <= n; ++t){
                for(int i = 1; i < siz; ++i) vis[i] = false;
                for(int i = 1, j = 0; i < siz; ++i){
                    while(j && S[t][j + 1] != t1[i]) j = nxt[0][t][j];
                    if(S[t][j + 1] == t1[i]) j++;
                    if(j == S[t].size() - 1){
                        // cout << t << ' ' << i << ' ' << j << '\n';
                        vis[i] = true; j = nxt[0][t][j];
                    }
                }
                for(int i = 1, j = 0; i < siz; ++i){
                    while(j && T[t][j + 1] != t2[i]) j = nxt[1][t][j];
                    if(T[t][j + 1] == t2[i]) j++;
                    if(j == T[t].size() - 1){
                        // cout << t << ' ' << i << ' ' << j << '\n';
                        if(vis[i] && i - (T[t].size() - 1) + 1 <= st && ed <= i) ans++;
                        j = nxt[1][t][j];
                    }
                }
                // cout << ans << '\n';
            }
            cout << ans << '\n';
        }
    }
}

signed main(){
    freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> S[i] >> T[i];
    int L1 = 0, L2 = 0;
    for(int i = 1; i <= q; ++i) cin >> t1[i] >> t2[i], L1 += t1[i].size(), L2 += t2[i].size();
    if(n <= 1e3 && L1 <= 2e3 && L2 <= 2e3) return sub1::solve(), 0;
    for(int i = 1; i <= n; ++i){
        // cin >> S[i] >> T[i];
        if(S[i] == T[i]) continue;
        int siz = S[i].size();
        st[i] = ed[i] = -1;
        for(int j = 0; j < siz; ++j){
            if(S[i][j] != T[i][j]){
                if(!~st[i]) st[i] = j; ed[i] = j;
            }
        }
        int ha = 0, ha1 = 0, ha2 = 0;
        for(int j = st[i]; j <= ed[i]; ++j){
            ha = (29ll * ha + S[i][j] - 'a' + 1) % mod;
            ha1 = 29ll * ha1 % mod, ha2 = 29ll * ha2 % mod;
            if(S[i][j] != T[i][j]){
                ha1 += S[i][j] - 'a' + 1, ha2 += T[i][j] - 'a' + 1;
            }
        }
        mp[(1ll * ha1 + 2333ll * ha2 + 19260817ll * ha) % mod].push_back(i);
        // cout << i << ' ' << st[i] << ' ' << ed[i] << '\n';
    }
    for(int i = 1; i <= q; ++i){
        // cin >> t1[i] >> t2[i];
        if(t1[i].size() != t2[i].size()) continue;
        int siz = t1[i].size();
        st1[i] = ed1[i] = -1;
        for(int j = 0; j < siz; ++j){
            if(t1[i][j] != t2[i][j]){
                if(!~st1[i]) st1[i] = j; ed1[i] = j;
            }
        }
        int ha = 0, ha1 = 0, ha2 = 0;
        for(int j = st1[i]; j <= ed1[i]; ++j){
            ha = (29ll * ha + t1[i][j] - 'a' + 1) % mod;
            ha1 = 29ll * ha1 % mod, ha2 = 29ll * ha2 % mod;
            if(t1[i][j] != t2[i][j]){
                ha1 += t1[i][j] - 'a' + 1, ha2 += t2[i][j] - 'a' + 1;
            }
        }
        int haa = (1ll * ha1 + 2333ll * ha2 + 19260817ll * ha) % mod;
        if(!mp[haa].size()) continue;
        que[haa].push_back(i);
    }
    for(auto _ : mp){
        int ha = _.first; vector<int> vec = _.second;
        if(!que[ha].size()) continue;
        Tr.clear();
        for(int i : vec){
            string s = ""; for(int j = 0; j < st[i]; ++j) s += S[i][j];
            Tr.insert(s, 0, i, 1);
        }
        for(int i : que[ha]){
            string s = ""; for(int j = 0; j < st1[i]; ++j) s += t1[i][j];
            Tr.get(s, i);
        }
        T1.clear(); dfs(1);
    }
    for(int i = 1; i <= q; ++i) cout << ans[i] << '\n';

    return 0;
}