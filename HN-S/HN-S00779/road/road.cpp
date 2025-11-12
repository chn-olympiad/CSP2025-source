#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
 int st = 1e5 + 2;
const int maxm = 4e6 + 10;
int c[maxn];

int n, m, k;
int head[maxn], nxt[maxm], to[maxm], val[maxm];
int tot = 1;

void adde(int u, int v, int w){
    to[++tot] = v;
    val[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;

}
int cnte;
struct edge{
    int v, w;
    int u;
}ed[maxm];
bool cmpe(edge x, edge y){
    return x.w < y.w;
}

ll dis[maxn];
int ins[maxn];

ll ans;
int f[maxn];

int fd(int x){
    if(x == f[x]) return x;
    else  f[x] = fd(f[x]);
    return f[x];

}
void prim(){
    sort(ed + 1, ed + 1 + cnte, cmpe);
    for(int i = 1; i <= cnte; i++){
        int u = ed[i].u, v = ed[i].v, w = ed[i].w;
        if(fd(u) != fd(v)) {
            ans += w;
            f[u] = fd(v);

            //printf("etst: %d %d %d\n", u, v, w);

        }
    }
}


int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n + k; i++) f[i] = i;

    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >>w;
        cnte++;
        ed[cnte].u = u;
        ed[cnte].v = v;
        ed[cnte].w = w;
        adde(u, v, w);
        adde(v, u, w);
    }
    st = 1;
    //if(k == 0) st = 1;

    for(int i = 1; i <= k; i++){
        cin >> c[i];
        int u = n + i, v = st, w = c[i];
        cnte++;
        ed[cnte].u = u;
        ed[cnte].v = v;
        ed[cnte].w = w;
        adde(n + i, st, c[i]);
        adde(st, n + i, c[i]);
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            u = j;
            v = n + i;
            w = x;
            cnte++;
        ed[cnte].u = u;
        ed[cnte].v = v;
        ed[cnte].w = w;
            adde(j, n + i, x);
            adde(n + i, j, x);
        }
    }

    prim();


    cout << ans <<endl;






    return 0;
}
