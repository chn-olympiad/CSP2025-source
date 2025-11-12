#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int maxn = 2e4 + 5;
const int maxm = (1 << 10) + 5;
const int maxk = 2e6 + 5;
int n, tmp[maxm][maxn], tp[maxm], m, fa[maxn], k, id[15][maxn], siz[15];
int c[maxn], b[maxk];
ll f[maxm];
struct edge{int u, v, w;}e[maxk], e1[maxk];
//记得拍 RE
void init(){
    for(int i = 1; i <= n + k; i++){
        fa[i] = i;
    }
}

int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> e1[i].u >> e1[i].v >> e1[i].w;
    }
    sort(e1 + 1, e1 + m + 1, [](edge x, edge y){
        return x.w < y.w;
    });
    init();
    int tot = 0;
    ll s = 0;
    for(int i = 1, j = 0; i <= m; i++){
        int u = e1[i].u, v = e1[i].v;
        u = find(u);
        v = find(v);
        if(u != v){
            j++;
            fa[u] = v;
            e[++tot] = e1[i];
            s += e1[i].w;
            if(j == n - 1){
                break;
            }
        }
    }
    f[0] = s;
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++){
            int w;
            cin >> w;
            e[++tot] = {i + n, j, w};
        }
    }
    sort(e + 1, e + tot + 1, [](edge x, edge y){
        return x.w < y.w;
    });
    ll ans = f[0];
    for(int i = 1; i <= tot; i++){
        int u = e[i].u, v = e[i].v;
        if(u <= n && v <= n){
            id[0][++siz[0]] = i;
            tmp[0][++tp[0]] = i;
        }else{
            int op = u - n;
            id[op][++siz[op]] = i;
        }
    }
    for(int i = 1; i < 1 << k; i++){
        for(int j = 0; j < k; j++){
            if(i >> j & 1){
                f[i] += c[j + 1];
            }
        }
        init();
        int s = i & (-i), t = i ^ s, x = __lg(s) + 1;
        merge(tmp[t] + 1, tmp[t] + tp[t] + 1, id[x] + 1, id[x] + siz[x] + 1, b + 1);
        int SIZ = __builtin_popcount(i) + n;
        for(int j = 1, p = 0; j <= tp[t] + siz[x]; j++){
            int u = e[b[j]].u, v = e[b[j]].v;
            u = find(u);
            v = find(v);
            if(u != v){
                fa[u] = v;
                p++;
                f[i] += e[b[j]].w;
                tmp[i][++tp[i]] = b[j];
                if(p == SIZ - 1){
                    break;
                }
            }
        }
        ans = min(ans, f[i]);
    }
    cout << ans << '\n';

    return 0;
}