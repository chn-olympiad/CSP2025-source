/*
META:
BJ-S00702 2025/11/1
road.cpp T2
Status=Locked
Guess Score=56
E1 ?
E2 ?
E3 ?
E4 ?
S1 ?
S2 ?
S3 ?
S4 ?
H1 ?
H2 ?
*/
/*
STESTS:

*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, k, ec = 0, ecbk = 0;
long long pri[10005][15], c[15];
bool used[15];
int fat[12005];
long long ans = 0;

int fnd(int x) {
    if (fat[x] == x) return x;
    return fat[x] = fnd(fat[x]);
}
void comb(int x, int y) {
    fat[fnd(y)] = fnd(x);
}

struct line {
    int u, v;
    long long w;
} e[2000005], tmp[2000005];

long long fread() {
    long long x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

void ae(int u, int v, long long w) {
    ec++;
    e[ec].u = u;
    e[ec].v = v;
    e[ec].w = w;
    return;
}

bool cmp(line x, line y) {
    return x.w < y.w;
}

void dfs(int now) {
    if (now > k) {
        ec = ecbk;
        long long tot = 0;
        for (int i = 1; i <= k; i++) {
            if (used[i]) {
                for (int j = 1; j <= n; j++) {
                    ae(i + n, j, pri[j][i]);
                }
                tot += c[i];
            }
        }
        for (int i = 1; i <= n + k; i++) fat[i] = i;
        for (int i = 1; i <= ec; i++) {
            tmp[i] = e[i];
        }
        sort(tmp + 1, tmp + ec + 1, cmp);
        for (int i = 1; i <= ec; i++) {
            if (fnd(tmp[i].u) == fnd(tmp[i].v)) continue;
            comb(tmp[i].u, tmp[i].v);
            tot += tmp[i].w;
        }
        ans = min(ans, tot);
        return;
    }
    used[now] = false;
    dfs(now + 1);
    used[now] = true;
    dfs(now + 1);
    return;
}

void solvec0() {
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            ae(n + i, j, pri[j][i]);
        }
    }
    for (int i = 1; i <= n + k; i++) fat[i] = i;
    sort(e + 1, e + ec + 1, cmp);
    for (int i = 1; i <= ec; i++) {
        if (fnd(e[i].u) == fnd(e[i].v)) continue;
        comb(e[i].u, e[i].v);
        //printf("ans(%d) += e[i(%d)].w(%d)\n", ans, i, e[i].w);
        ans += e[i].w;
    }
    return;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = fread(); m = fread(); k = fread();
    for (int i = 1; i <= m; i++) {
        int x, y;
        long long z;
        x = fread(); y = fread(); z = fread();
        ae(x, y, z);
    }
    ecbk = ec;
    bool c0 = true;
    for (int i = 1; i <= k; i++) {
        c[i] = fread();
        if (c[i] != 0) c0 = false;
        for (int j = 1; j <= n; j++) {
            pri[j][i] = fread();
        }
    }
    if (c0) solvec0();
    else {
        ans = 0x3f3f3f3f3f3f3f3f;
        dfs(1);
    }
    cout << ans << endl;
    return 0;
}
