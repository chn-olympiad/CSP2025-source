#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, t;
    friend bool operator <(const edge &a, const edge &b){
        return a.t < b.t;
    }
} Oe[1000005], Te[10005], e[210005];

int n, m, k, w[10015], G, z;
int f[10015], d[10015];
int Ne[15][10005];
long long ans, cs[10015];
bool sp;

int find(int x){
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k); sp = true;
    for (int i = 1; i <= m; i++){
        int u, v, t; scanf("%d%d%d", &u, &v, &t);
        Oe[i] = {u, v, t};
    }

    for (int i = 1; i <= n; i++){
        f[i] = i;
    }
    sort(Oe+1, Oe+m+1);
    for (int i = 1; i <= m; i++){
        int fu = find(Oe[i].u), fv = find(Oe[i].v);
        if (fu == fv) continue;
        f[fu] = fv; Te[++G] = Oe[i];
    }
    for (int i = 1; i <= k; i++){
        scanf("%d", &w[i]); if (w[i] != 0) sp = false;
        for (int j = 1; j <= n; j++){
            scanf("%d", &Ne[i][j]);
        }
    }

    if (sp){
        for (int i = 1; i <= n + k; i++){
            f[i] = i;
        }
        for (int i = 1; i <= G; i++){
            e[++z] = Te[i];
        }
        for (int i = 1; i <= k; i++){
            for (int j = 1; j <= n; j++){
                e[++z] = {n + i, j, Ne[i][j]};
            }
        }
        sort(e+1, e+z+1);
        for (int i = 1; i <= z; i++){
            int fu = find(e[i].u), fv = find(e[i].v);
            if (fu == fv) continue;
            f[fu] = fv; 
            d[e[i].u]++; d[e[i].v]++;
            cs[e[i].u] += e[i].t; cs[e[i].v] += e[i].t;
            ans += e[i].t;
        }
        for (int i = 1; i <= k; i++){
            if (d[n + i] == 1) ans -= cs[n + i];
        }
        printf("%lld\n", ans);
        return 0;
    }
    ans = 9e18;
    for (int st = 0; st < (1 << k); st++){
        int x = st; z = 0; long long ret = 0;
        for (int i = 1; i <= n + k; i++){
            f[i] = i; d[i] = cs[i] = 0;
        }
        for (int i = 1; i <= G; i++){
            e[++z] = Te[i];
        }
        while (x){
            int low = x & -x, p = log2(low) + 1;
            x -= low; ret += w[p];
            for (int j = 1; j <= n; j++){
                e[++z] = {n + p, j, Ne[p][j]};
            }
        }
        sort(e+1, e+z+1);
        for (int i = 1; i <= z; i++){
            int fu = find(e[i].u), fv = find(e[i].v);
            if (fu == fv) continue;
            f[fu] = fv; 
            d[e[i].u]++; d[e[i].v]++;
            cs[e[i].u] += e[i].t; cs[e[i].v] += e[i].t;
            ret += e[i].t;
        }
        for (int i = 1; i <= k; i++){
            if (d[n + i] == 1) ret -= cs[n + i];
        }
        ans = min(ans, ret);
    }
    printf("%lld\n", ans);
    return 0;
}