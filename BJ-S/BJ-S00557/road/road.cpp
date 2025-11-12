#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll inf = 0x7fffffff;
const int Maxn = 1e4 + 5;
const int Maxm = 2e7 + 5;

int nowm, nown, cur;
int n, m, fa[Maxn], k;
ll c[Maxn], a[10][Maxn], ans;

ll Min(ll a, ll b){
    return a < b ? a : b;
}

struct edge{
    int from, to;
    ll val;
}e[Maxm << 1], _e[Maxm << 1];
int tot, _tot;
void add(int u, int v, int w){
    e[++ tot].from = u;
    e[tot].to = v;
    e[tot].val = w;
}

void _add(int u, int v, int w){
    _e[++ _tot].from = u;
    _e[_tot].to = v;
    _e[_tot].val = w;
}

bool cmp(edge a, edge b){
    return a.val < b.val;
}

int getf(int u){
    if(fa[u] == u) return u;
    else return fa[u] = getf(fa[u]);
}

void ufs(int x, int y){
    x = getf(x), y = getf(y);
    if(fa[x] != fa[y]) fa[x] = y;
}

void krustal(){
    int cnt = 0;
    //printf("debug_nown_nowm : %d %d\n", nown, nowm);
    for(int i = 1; i <= nown; i ++) fa[i] = i;
    sort(_e + 1, _e + 1 + nowm, cmp);
    //printf("debug: _e.val:");
    //for(int i = 1; i <= nowm; i ++) cout << _e[i].val << ' ';
    for(int i = 1; i <= nowm; i ++){
        //cout << 1;
        int u = _e[i].from, v = _e[i].to;
        if(getf(u) == getf(v)) continue;
        //printf("debug_fa: %d %d\n", getf(u), getf(v));
        //printf("debug_from_to: %d %d\n", _e[i].from, _e[i].to);
        cur += _e[i].val;
        //cout << "debug_cur:" << cur << '\n';
        ufs(u, v);
        if(++ cnt == nown - 1) break;
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ans = inf;
    cin >> n >> m >> k;

    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    for(int i = 1; i <= k; i ++){
        cin >> c[i];
        for(int j = 1; j <= n; j ++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < (1 << k); i ++){
        int tmp = i, cnt = 0;
        nowm = 2 * m, nown = n, cur = 0;
        memcpy(_e, e, sizeof(_e));
        _tot = tot;
        while(tmp){
            int d = tmp & 1;
            cnt ++;
            if(d == 1){
                nown ++;
                for(int i = 1; i <= n; i ++){
                    _add(nown, i, a[cnt][i]);
                    _add(i, nown, a[cnt][i]);
                    nowm += 2;
                }
                cur += c[cnt];
            }
            tmp >>= 1;
        }
        krustal();
        //printf("debug_cur_ans:%d %d\n", cur, ans);
        ans = Min(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}
