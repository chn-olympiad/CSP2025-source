#include<bits/stdc++.h>
#define FILE "replace"
using namespace std;

namespace FakeWilson {
const int mod = 1e9 + 9;
const int B = 13131;
const int N = 2e5 + 5;
const int M = 5e6 + 5;
int tr[N + M][31], ed[N + M], rt[N], fail[N + M], Q[N + M];
map<pair<int, int>, int> mp;
int cnt, node_cnt;
char s[M], t[M];

void insert(int p, int len) {
    for(int i = 1; i <= len; i++) {
        int c = s[i] - 'a';
        if(!tr[p][c]) tr[p][c] = ++node_cnt;
        p = tr[p][c];
    }
    ed[p]++;
    // cout << p << " " << ed[p] << endl;
}

void build(int rt) {
    int hd = 1, tl = 0;
    for(int i = 0; i < 27; i++) if(tr[rt][i]) Q[++tl] = tr[rt][i];
    while(hd <= tl) {
        int p = Q[hd]; hd++;
        // cout << "QWQ" << p << endl;
        ed[p] += ed[fail[p]];
        // cout << p << " " << fail[p] << " " << ed[p] << endl;
        for(int i = 0; i < 27; i++) {
            if(tr[p][i]) fail[tr[p][i]] = tr[fail[p]][i], Q[++tl] = tr[p][i];
            else tr[p][i] = tr[fail[p]][i];
        }
    }
}

void calc(bool f) {
    int n = strlen(s + 1);
    int l = 1, r = n;
    for(int i = 1; i <= n; i++) {
        if(s[i] != t[i]) break;
        l++;
    }
    for(int i = n; i >= 1; i--) {
        if(s[i] != t[i]) break;
        r--;
    }
    int hs1 = 0, hs2 = 0;
    for(int i = l; i <= r; i++) {
        hs1 = (1LL * hs1 * B % mod + s[i] - 'a') % mod;
        hs2 = (1LL * hs2 * B % mod + t[i] - 'a') % mod;
    }
    for(int i = l; i <= r; i++) s[i] = '{';
    // cout << l << " " << r << endl;
    if(f) {
        if(!mp[make_pair(hs1, hs2)]) {
            mp[make_pair(hs1, hs2)] = ++cnt;
            rt[cnt] = ++node_cnt;
        }
        int _ = mp[make_pair(hs1, hs2)];
        // cout << _ << endl;
        insert(rt[_], n);
    } else {
        if(!mp[make_pair(hs1, hs2)]) {puts("0"); return;}
        int _ = mp[make_pair(hs1, hs2)];
        int p = rt[_], ans = 0;
        for(int i = 1; i <= n; i++) {
            p = tr[p][s[i] - 'a'];
            ans += ed[p];
            // cout << p << " " << ans << endl;
        }
        printf("%d\n", ans);
    }
}

signed main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%s%s", s + 1, t + 1);
        calc(true);
    }
    for(int i = 1; i <= cnt; i++) build(rt[i]);
    while(q--) {
        scanf("%s%s", s + 1, t + 1);
        calc(false);
    }
    return 0;
}

}

signed main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    return FakeWilson::main();
}

