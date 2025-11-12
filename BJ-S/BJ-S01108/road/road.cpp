#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 5;
const int D = 20005;

bool AAA;

struct dat {
    int x, y, z;
    bool operator < (const dat &o) const {
        return z < o.z;
    }
} e[N], e1[D*10], e2[N],ee[N];

int n, m, k, cnt;

int fa[D];
int c[11], a[11][D], fl[11];
int b[11];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

bool BBB;

int id[N], mn[N];

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1, x, y, z; i <= m; i++) {
        cin >> x >> y >> z;
        e[++cnt] = {x, y, z};
    }
    int tot = 0;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
        if (c[i]) {
            b[++tot] = i;
            continue;
        }
        for (int j = 1; j <= n; j++)
            if (!a[i][j]) {
                fl[i] = 1;
                for (int l = 1; l <= n; l++)
                    e[++cnt] = {j, l, a[i][l]};
                break;
            }
        if (!fl[i]) b[++tot] = i;
    }
    int ans = 1e18,kkk=0;
    sort(e + 1, e + cnt + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= cnt; i++) {
        int fx = find(e[i].x), fy = find(e[i].y);
        if (fx == fy) continue;
        ee[++kkk] = e[i];
        fa[fy] = fx;
    }
    for (int i = 1; i <= kkk; i++)
        e[i] = ee[i];
    cnt = kkk;
    for (int S = 0; S < (1 << tot); S++) {
        int tmp = 0, tmp1 = 0, res = 0, tt = 0;
        for(int j=1;j<=n;j++)
            mn[j]=1e18,id[j]=0;
        for (int i = 0; i < tot; i++) {
            if (!(S >> i & 1)) continue;
            res += c[b[i + 1]];
            tt++;
            for (int j = 1; j <= n; j++){
                if(a[b[i+1]][j]<mn[j]){
                    mn[j]=a[b[i+1]][j];
                    id[j]=tt;
                }
            }
                //e1[++tmp1] = {tt + n, j, a[b[i + 1]][j]};
        }
        for(int j=1;j<=n;j++)
            e1[++tmp1]={id[j]+n,j,mn[j]};
        sort(e1 + 1, e1 + tmp1 + 1);
        for (int i = 1, j = 1; i <= cnt; i++) {
            while (j <= tmp1 && e1[j] < e[i]) e2[++tmp] = e1[j++];
            e2[++tmp] = e[i];
        }
        for (int i = 1; i <= n + tt; i++)
            fa[i] = i;
        int bs = 0;
        for (int i = 1; i <= tmp; i++) {
            int fx = find(e2[i].x), fy = find(e2[i].y);
            if (fx == fy) continue;
            res += e2[i].z;
            fa[fy] = fx;
            bs++;
            if (bs == n + tt - 1) break;
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
    //cerr<<((&AAA)-(&BBB))/1024.0/1024<<"MB\n";
    return 0;
}