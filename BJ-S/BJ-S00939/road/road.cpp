#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Edge{
    long long ll, rr, ww;
}edge[1100005];

long long n, m, k, c[15], fa[11005], i, j, ecnt, ans = -1, anstt, si[11005], edgelen, edgepp[1100005];
bool xl[15], flaga, flagatt;

bool cmp(Edge a, Edge b) {
    return a.ww < b.ww;
}

long long find_fa(long long nod) {
    if (nod == fa[nod])
        return nod;
    fa[nod] = find_fa(fa[nod]);
    return fa[nod];
}

void dfs(long long loc, long long cho, long long tttt) {
    if (ans != -1 && tttt >= ans)
        return;
    if (loc == k + 1) {
        anstt = tttt;
        for (i = 1;i <= n + k;i++) {
            fa[i] = i;
            si[i] = 1;
        }
        ecnt = 0;
        for (j = 1;j <= edgelen && ecnt < n + cho - 1;j++) {
            if (edge[j].ll > n && !xl[edge[j].ll - n])
                continue;
            long long tta = find_fa(edge[j].ll), ttb = find_fa(edge[j].rr);
            if (tta != ttb) {
                if (si[tta] <= si[ttb]) {
                    fa[tta] = ttb;
                    si[ttb] += si[tta];
                    si[tta] = 0;
                }
                else {
                    fa[ttb] = tta;
                    si[tta] += si[ttb];
                    si[ttb] = 0;
                }
                anstt += edge[j].ww;
                if (ans != -1 && anstt >= ans)
                    return;
                ecnt++;
            }
        }
        ans = anstt;
        return;
    }
    xl[loc] = false;
    dfs(loc + 1, cho, tttt);
    xl[loc] = true;
    dfs(loc + 1, cho + 1, tttt + c[loc]);
    xl[loc] = false;
    return;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (i = 1;i <= m;i++) {
            scanf("%d%d%d", &(edge[i].ll), &(edge[i].rr), &(edge[i].ww));
    }
    edgelen = m;
    flaga = true;
    for (i = 1;i <= k;i++) {
        scanf("%d", c + i);
        if (c[i] != 0)
            flaga = false;
        flagatt = false;
        for (j = 1;j <= n;j++) {
            edge[++edgelen].ll = n + i;
            scanf("%d", &(edge[edgelen].ww));
            edge[edgelen].rr = j;
            if (edge[edgelen].ww == 0)
                flagatt = true;
        }
        if (!flagatt)
            flaga = false;
    }
    sort(edge + 1, edge + edgelen + 1, cmp);
    if (k == 0 || flaga) {
        ans = 0;
        for (i = 1;i <= n + k;i++) {
            fa[i] = i;
            si[i] = 1;
        }
        ecnt = 0;
        for (j = 1;j <= edgelen && ecnt < n + k - 1;j++) {
            long long tta = find_fa(edge[j].ll), ttb = find_fa(edge[j].rr);
            if (tta != ttb) {
                if (si[tta] <= si[ttb]) {
                    fa[tta] = ttb;
                    si[ttb] += si[tta];
                    si[tta] = 0;
                }
                else {
                    fa[ttb] = tta;
                    si[tta] += si[ttb];
                    si[ttb] = 0;
                }
                ans += edge[j].ww;
                ecnt++;
            }
        }
        cout << ans << endl;
        return 0;
    }

    dfs(1, 0, 0);
    cout << ans << endl;

    return 0;
}
