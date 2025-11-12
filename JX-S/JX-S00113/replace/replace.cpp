/*
    Author : Sparkle_ZH & Sparklee
    Right Output ! & Accepted !
*/

#include <bits/stdc++.h>
#define lowbit(x) ((x) & (- (x)))
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define ll long long
#define fir first
#define sec second
using namespace std;

template<typename T> inline void write(T x, int f = -1) {
    if (x < 0) putchar('-'), x = -x;
    static short Stack[50], top(0);
    do Stack[++ top] = x % 10, x /= 10; while (x);
    while (top) putchar(Stack[top --] | 48);
    if (~ f) putchar(f ? '\n' : ' ');
}

const int N = 6e6 + 5;
int n, q, cnt, stk[N], siz[N], fail[N], ch[N][27];
char s1[N], s2[N], str[N];
bool f[N];

void ins(int m) {
    int p = 0;
    for (int i = 1; i <= m; i ++) {
        int v = str[i] - 'a';
        if (! ch[p][v]) ch[p][v] = ++ cnt;
        p = ch[p][v];
    }
    siz[p] ++;
}

void bfs() {
    queue<int> Q;
    for (int i = 0; i < 27; i ++)
        if (ch[0][i]) Q.push(ch[0][i]);

    while (! Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < 27; i ++) {
            if (ch[u][i]) {
                fail[ch[u][i]] = ch[fail[u]][i];
                Q.push(ch[u][i]);
            } else ch[u][i] = ch[fail[u]][i];
        }
    }

    if (q != 1 && cnt > 1100000) {
        f[0] = 1;
        for (int i = 0; i < 27; i ++)
            if (ch[0][i]) f[ch[0][i]] = 1, Q.push(ch[0][i]);

        while (! Q.empty()) {
            int u = Q.front(); Q.pop();
            if (! siz[fail[u]]) fail[u] = fail[fail[u]];
            for (int i = 0; i < 27; i ++)
                if (! f[ch[u][i]])
                    f[ch[u][i]] = 1, Q.push(ch[u][i]);
        }

        fill(f, f + 1 + cnt, 0);
    }
}

int query(int m) {
    int p = 0, s = 0, top = 0;
    for (int i = 1; i <= m; i ++) {
        int v = str[i] - 'a';
        p = ch[p][v];
        for (int j = p; j; j = fail[j]) {
            if (f[j]) break;
            stk[++ top] = j, s += siz[j], f[j] = 1;
        }
    }
    while (top) f[stk[top --]] = 0;
    return s;
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i ++) {
        scanf("%s", s1 + 1);
        scanf("%s", s2 + 1);

        int m = strlen(s1 + 1), l = m, r = 0, len = 0;

        for (int j = 1; j <= m; j ++)
            if (s1[j] != s2[j])
                l = min(l, j), r = max(r, j);

        if (! l) continue ;

        for (int j = 1; j < l; j ++)
            str[++ len] = s1[j];
        str[++ len] = 'z' + 1;
        for (int j = l; j <= r; j ++)
            str[++ len] = s1[j], str[++ len] = s2[j];
        str[++ len] = 'z' + 1;
        for (int j = r + 1; j <= m; j ++)
            str[++ len] = s1[j];

        ins(len);
    }

    bfs();

    while (q --) {
        scanf("%s", s1 + 1);
        scanf("%s", s2 + 1);

        if (strlen(s1 + 1) != strlen(s2 + 1)) { puts("0"); continue ; }
        int m = strlen(s1 + 1), l = m, r = 0, len = 0;

        for (int j = 1; j <= m; j ++)
            if (s1[j] != s2[j])
                l = min(l, j), r = max(r, j);

        for (int j = 1; j < l; j ++)
            str[++ len] = s1[j];
        str[++ len] = 'z' + 1;
        for (int j = l; j <= r; j ++)
            str[++ len] = s1[j], str[++ len] = s2[j];
        str[++ len] = 'z' + 1;
        for (int j = r + 1; j <= m; j ++)
            str[++ len] = s1[j];

        write(query(len), 1);
    }

    return 0;
}
