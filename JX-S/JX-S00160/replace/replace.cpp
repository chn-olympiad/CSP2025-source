#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
const int N = 5e6 + 5;
bool vis[N], back[N];
char S[N], S1[N], S2[N];
int n, m, idx, tmp, dep[N], cnt[N], fail[N], son[N][30];
inline void insert () {
    int p = 0, len = tmp;
    for (int i = 1, c; i <= len; i++) {
        c = S[i] - 'a';
        if (!son[p][c]) son[p][c] = ++idx, dep[idx] = dep[p] + 1;
        p = son[p][c];
    }
    cnt[p]++;
}
inline void init () {
    int len = tmp;
    vis[0] = back[len + 1] = true;
    for (int i = 2; i <= len; i += 2) {
        vis[i] = vis[i - 2];
        if (S[i] != S[i - 1]) vis[i] = false;
    }
    for (int i = len - 1; i > 0; i -= 2) {
        back[i] = back[i + 2];
        if (S[i] != S[i + 1]) back[i] = false;
    }
}
int head = 1, tail, q[N];
void build () {
    FOR(i, 0, 25) if (son[0][i]) q[++tail] = son[0][i];
    while (head <= tail) {
        int u = q[head++];
        for (int i = 0, v; i < 26; i++) {
            v = son[u][i];
            if (!v) son[u][i] = son[fail[u]][i];
            else fail[v] = son[fail[u]][i], q[++tail] = v;
        }
    }
}
inline ll query () {
    ll res = 0;
    int p = 0, len = tmp;
    for (int i = 1, c, l, r = 2; i <= len; i++, r++) {
        c = S[i] - 'a', p = son[p][c];
        if (!back[r]) continue;
        int u = p;
        while (u) {
            l = i - dep[u];
            if (vis[l]) res += cnt[u];
            else if (!(dep[u] & 1)) break;
            u = fail[u];
        }        
    }
    return res;
}
int main () {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m, vis[0] = true;
    for (int i = 1, len; i <= n; i++) {
        cin >> S1 + 1 >> S2 + 1, len = strlen(S1 + 1), tmp = 0;
        for (int j = 1; j <= len; j++) S[++tmp] = S1[j], S[++tmp] = S2[j];
        insert();
    }
    build();
    for (int i = 1, len; i <= m; i++) {
        cin >> S1 + 1 >> S2 + 1, len = strlen(S1 + 1), tmp = 0;
        for (int j = 1; j <= len; j++) S[++tmp] = S1[j], S[++tmp] = S2[j];
        init(), cout << query() << '\n';
    }//xuan xue fu za du
    return 0;
}