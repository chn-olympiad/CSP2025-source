// caution: 5e8 2200ms running time auto div 2.2
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int max(int x, int y, int z) {return max(max(x, y), z);}
int min(int x, int y, int z) {return min(min(x, y), z);}
int tmp[3];
int mid(int x, int y, int z) {
    tmp[0] = x, tmp[1] = y, tmp[2] = z;
    sort(tmp, tmp + 3);
    return tmp[1];
}
struct node {
    int p[3], c, lnum, mnum;
} a[N];
int n, lim;
const bool operator < (const node &x, const node &y) {return x.c > y.c;}
priority_queue<node> pq[3];
void pd() {
    for (int i = 0; i < 3; i++) while (pq[i].size()) pq[i].pop();
    cin >> n; lim = n / 2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].p[0] >> a[i].p[1] >> a[i].p[2];
        a[i].c = max(a[i].p[0], a[i].p[1], a[i].p[2]) - mid(a[i].p[0], a[i].p[1], a[i].p[2]);
        a[i].lnum = a[i].mnum = -1;
        if (a[i].c != 0) {
            int mx = max(a[i].p[0], a[i].p[1], a[i].p[2]), md = mid(a[i].p[0], a[i].p[1], a[i].p[2]);
            for (int j = 0; j < 3; j++) {
                if (a[i].p[j] == mx) a[i].lnum = j;
                if (a[i].p[j] == md) a[i].mnum = j;
            }
        } else {
            int mx = max(a[i].p[0], a[i].p[1], a[i].p[2]);
            for (int j = 0; j < 3; j++) {
                if (a[i].p[j] == mx) {
                    if (a[i].lnum == -1) a[i].lnum = j;
                    else a[i].mnum = j;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        node now = a[i];
        if (pq[now.lnum].size() == lim) {
            if (pq[now.lnum].top().c < now.c) {
                node cg = pq[now.lnum].top();
                pq[now.lnum].pop();
                pq[now.lnum].push(now);
                pq[cg.mnum].push(cg);
                ans -= cg.p[cg.lnum];
                ans += cg.p[cg.mnum];
                ans += now.p[now.lnum];
            } else {
                pq[now.mnum].push(now);
                ans += now.p[now.mnum];
            }
        } else {
            pq[now.lnum].push(now);
            ans += now.p[now.lnum];
        }
    }
    cout << ans << '\n';
    return;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _;
    cin >> _;
    while (_--) pd();
    return 0;
}