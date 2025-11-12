#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll Read() {
    int sig = 1; ll x = 0; char c = getchar();
    while(!isdigit(c)) { if(c == '-') sig = -1; c = getchar(); }
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    return x * sig;
}
void Write(ll x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) Write(x / 10);
    putchar((x % 10) ^ 48);
}
const int N = 200005, L = 5200005;
int n, k, q, que[L], front, back; ll ans[N];
vector<string> vec[N];
vector<pair<string, int> > query[N];
pair<string, string> Find(string s1, string s2) {
    int i, n = s1.size(), p = -1, q = -1; string t1, t2;
    for(i = 0; i < n; i++) if(s1[i] != s2[i]) { q = i; if(p == -1) p = i; }
    if(p == -1) return make_pair("", s1);
    for(i = 0; i < p; i++) t2.push_back(s1[i]), t2.push_back(s2[i]);
    t2.push_back('{');
    for(i = p; i <= q; i++) t1.push_back(s1[i]), t1.push_back(s2[i]);
    for(i = q + 1; i < n; i++) t2.push_back(s1[i]), t2.push_back(s2[i]);
    return make_pair(t1, t2);
}
void Read_Str(string &s) {
    char c = getchar();
    while(c < 'a' || c > 'z') c = getchar();
    while(c >= 'a' && c <= 'z') s.push_back(c), c = getchar();
}
struct DS {
    int tot, son[27][L], cnt[L], fail[L];
    void Trie_Insert(string s, string t) {
        int i, u = 1, n = s.size();
        for(i = 0; i < n; i++) {
            int &x = son[s[i] - 'a'][u];
            if(!x) x = ++tot;
            u = x;
        }
        if(!cnt[u]) cnt[u] = ++k;
        vec[cnt[u]].emplace_back(t);
    }
    void Trie_Find(string s, string t, int id) {
        int i, u = 1, n = s.size();
        for(i = 0; i < n; i++) {
            int x = son[s[i] - 'a'][u];
            if(!x) return ;
            u = x;
        }
        if(cnt[u]) query[cnt[u]].emplace_back(t, id);
    }
    void Clear(int x) { for(int i = 0; i <= 26; i++) son[i][x] = 0; cnt[x] = fail[x] = 0; }
    void AC_Insert(string s) {
        int i, u = 1, n = s.size();
        for(i = 0; i < n; i++) {
            int &x = son[s[i] - 'a'][u];
            if(!x) x = ++tot, Clear(tot);
            u = x;
        }
        cnt[u]++;
    }
    void AC_Build() {
        int i; front = 1, back = 0;
        for(i = 0; i <= 26; i++) if(son[i][1]) que[++back] = son[i][1], fail[son[i][1]] = 1;
        else son[i][1] = 1;
        while(front <= back) {
            int u = que[front++];
            for(i = 0; i <= 26; i++) if(son[i][u]) fail[son[i][u]] = son[i][fail[u]], cnt[son[i][u]] += cnt[fail[son[i][u]]], que[++back] = son[i][u];
            else son[i][u] = son[i][fail[u]];
        }
    }
    ll AC_Calc(string s) {
        int i, u = 1, n = s.size(); ll ans = 0;
        for(i = 0; i < n; i++) {
            int x = son[s[i] - 'a'][u];
            u = x, ans += cnt[u];
        }
        return ans;
    }
}ds;
int main() {
    freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
    int i; n = Read(), q = Read(), ds.tot = 1;
    for(i = 1; i <= n; i++) {
        string s1, s2; Read_Str(s1), Read_Str(s2);
        pair<string, string> p = Find(s1, s2);
        if(!p.first.empty()) ds.Trie_Insert(p.first, p.second);
    }
    for(i = 1; i <= q; i++) {
        string t1, t2; Read_Str(t1), Read_Str(t2);
        pair<string, string> p = Find(t1, t2);
        ds.Trie_Find(p.first, p.second, i);
    }
    for(i = 1; i <= k; i++) {
        ds.tot = 1, ds.Clear(1);
        for(auto s : vec[i]) ds.AC_Insert(s);
        ds.AC_Build();
        for(auto p : query[i]) ans[p.second] = ds.AC_Calc(p.first);
    }
    for(i = 1; i <= q; i++) Write(ans[i]), putchar('\n');
}
