#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
#define mkp make_pair
typedef pair<ULL, ULL> pUU;
const ULL B1 = 1331, B2 = 55667, mod = 1e9 + 7;
const int N = 2e5 + 5, LEN = 5e6 + 5;
struct Trie {
    vector<int>vec;
    int ch[30];
    Trie() { memset(ch, 0, sizeof 0); vec.clear(); }
}T[2][LEN];
int root[N], cntn;
map<pUU, int>mp[2];
int n, q;
char s1[LEN], s2[LEN];
int m;
inline void insert(int p, int c, char* s, int n, int id) {
    for (int i = 1;i <= n;++i) {
        int j = s[i] - 'a';
        if (!T[c][p].ch[j]) T[c][p].ch[j] = ++cntn;
        p = T[c][p].ch[j];
    }
    T[c][p].vec.push_back(id);
}
inline vector<int>query(int p, char* s, int c, int n) {
    vector<int>ret;
    for (int i = 1;i <= n;++i) {
        for (auto j : T[c][p].vec) ret.push_back(j);
        int j = s[i] - 'a';
        if (!T[c][p].ch[j]) return ret;
        p = T[c][p].ch[j];
    }
    for (auto j : T[c][p].vec) ret.push_back(j);
    return ret;
}
bool vis[N];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1;i <= n;++i) {
        scanf("%s%s", s1 + 1, s2 + 1);
        m = strlen(s1 + 1);
        int l = -1, r = -1;
        for (int i = 1;i <= m;++i) {
            if (l == -1 && s1[i] != s2[i]) l = i;
            if (s1[i] != s2[i]) r = i;
        }
        if (l == -1 || r == -1) continue;
        ULL h1 = 0, h2 = 0;
        for (int i = l;i <= r;++i) {
            h1 = h1 * B1 + s1[i];
            h2 = (h2 * B2 + s2[i]) % mod;
        }
        int p = mp[0][mkp(h1, h2)];
        if (!p) p = mp[0][mkp(h1, h2)] = ++cntn;
        if (l > 1) reverse(s1 + 1, s1 + l);
        insert(p, 0, s1, l - 1, i);
        p = mp[1][mkp(h1, h2)];
        if (!p) p = mp[1][mkp(h1, h2)] = ++cntn;
        insert(p, 1, s1 + r, m - r, i);
    }
    while (q--) {
        scanf("%s%s", s1 + 1, s2 + 1);
        m = strlen(s1 + 1);
        if (m != strlen(s2 + 1)) {
            puts("0");
            continue;
        }
        int l = -1, r = -1;
        for (int i = 1;i <= m;++i) {
            if (l == -1 && s1[i] != s2[i]) l = i;
            if (s1[i] != s2[i]) r = i;
        }
        ULL h1 = 0, h2 = 0;
        for (int i = l;i <= r;++i) {
            h1 = h1 * B1 + s1[i];
            h2 = (h2 * B2 + s2[i]) % mod;
        }
        int p = mp[0][mkp(h1, h2)];
        if (!p) {
            puts("0");
            continue;
        }
        if (l > 1) reverse(s1 + 1, s1 + l);
        vector<int>a = query(p, s1, 0, l - 1), b = query(mp[1][mkp(h1, h2)], s1 + r, 1, m - r);
        for (auto p : a) vis[p] = true;
        int ans = 0;
        for (auto p : b) ans += vis[p];
        for (auto p : a) vis[p] = false;
        printf("%d\n", ans);
    }
    return 0;
}