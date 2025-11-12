#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

inline int read() {
    int x = 0, w = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') w = -w; c = getchar(); }
    while (isdigit(c)) { x = (x << 3) + (x << 1) + c - 48; c = getchar(); }
    return x * w;
}

inline void write(long long x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}

int n;
int m;
int k;
pair<int, pair<int, int>> E[1000005];
int c[15];
int a[11][10005];
int fa[10015];
pair<int, pair<int, int>> E2[11][10005];
long long res;
long long ans = 0x3f3f3f3f3f3f3f3f;
int cnt;
int now[15];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    n = read(), m = read(), k = read();

    for (int i = 1; i <= n; i++)
        fa[i] = i;

    for (int i = 1, u, v, w; i <= m; i++) {
        u = read(), v = read(), w = read();
        E[i] = make_pair(w, make_pair(u, v));
    }

    for (int i = 1; i <= k; i++) {
        c[i] = read();
        for (int j = 1, w; j <= n; j++) {
            w = read();
            E2[i][j] = make_pair(w, make_pair(i + n, j));
        }
        sort(E2[i] + 1, E2[i] + n + 1);
    }

    sort(E + 1, E + m + 1);

    for (int i = 1; i <= m; i++) {
        int x = find(E[i].se.fi), y = find(E[i].se.se);
        if (x != y) {
            E2[0][++cnt] = E[i];
            fa[x] = y;
        }
    }

    int s = n + k;

    for (int i = 0; i < (1 << k); i++) {
        res = 0;

        for (int j = 1; j <= s; j++)
            fa[j] = j;

        for (int j = 0; j <= k; j++)
            now[j] = 1;

        for (int j = 1; j <= k; j++)
            if (i & (1 << (j - 1)))
                res += c[j];

        while (1) {
            int minw = 0x3f3f3f3f, t = -1;
            for (int j = 0; j <= k; j++) {
                if (!j && now[j] > cnt)
                    continue;
                if (j && !(i & (1 << (j - 1))))
                    continue;
                if (j && now[j] > n)
                    continue;
                if (E2[j][now[j]].fi < minw)
                    t = j, minw = E2[j][now[j]].fi;
            }
            if (t == -1)
                break;
            int x = find(E2[t][now[t]].se.fi), y = find(E2[t][now[t]].se.se);
            if (x != y) {
                res += E2[t][now[t]].fi;
                fa[x] = y;
            }
            now[t]++;
        }

        ans = min(ans, res);
    }

    write(ans);
    puts("");

    return 0;
}
