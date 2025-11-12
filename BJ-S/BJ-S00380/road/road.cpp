#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
int n, m, k, c[15];
long long ans = inf;
int f[200005], tot = 0, cnt = 0, tmp_cnt = 0;
struct edge{
    int u, u2;
    long long w;
    edge(){
    }
    edge(int _u, int _u2, long long _w){
        u = _u;
        u2 = _u2;
        w = _w;
    }
    inline bool operator <(const edge &o)const{
        return w < o.w;
    }
}e[1000015], a[15][10015], tr[200005], com[200005], tmp[200005];
inline void init(){
    for(int i = 1;i <= n + 20;i++){
        f[i] = i;
    }
}
inline int find(int x){
    if(f[x] == x){
        return x;
    }
    f[x] = find(f[x]);
    return f[x];
}
inline bool combine(int x, int y){
    int xx = find(x), yy = find(y);
    if(xx == yy){
        return 0;
    }
    f[xx] = yy;
    return 1;
} 
inline void init_m(){
    init();
    long long res = 0;
    for(int i = 1;i <= m;i++){
        if(combine(e[i].u, e[i].u2)){
            tr[++tot] = e[i];
            res += e[i].w;
        }
    }
    ans = min(ans, res);
    //cerr << tot << " " << res << "\n";
}
void dfs(int now, long long val){
    if(now >= k){
        // kruskal combine_sort com[] tr[]
        int x = 1, y = 1;
        long long res = 0;
        init();
        while(x <= cnt && y <= tot){
            if(com[x] < tr[y]){
                if(combine(com[x].u, com[x].u2)){
                    res += com[x].w;
                }
                x++;
            }
            else{
                if(combine(tr[y].u, tr[y].u2)){
                    res += tr[y].w;
                }
                y++;
            }
        }
        while(x <= cnt){
            if(combine(com[x].u, com[x].u2)){
                res += com[x].w;
            }
            x++;
        }
        while(y <= tot){
            if(combine(tr[y].u, tr[y].u2)){
                res += tr[y].w;
            }
            y++;
        }
        ans = min(ans, res + val);
        //cerr << val << " " << res << "\n";
        //for(int i = 1;i <= tot;i++){
        //    cout << tr[i].w << " ";
        //}
        //cout << "\n";
        //for(int i = 1;i <= cnt;i++){
        //    cout << com[i].w << " ";
        //}
        //cout << "\n";
        return;
    }
    dfs(now + 1, val);
    int _cnt = cnt;
    vector<edge> _com(cnt + 1);
    for(int i = 1;i <= cnt;i++){
        _com[i] = com[i];
    }
    // combine_sort a[now][], com[]
    int x = 1, y = 1;
    tmp_cnt = 0;
    while(x <= n && y <= cnt){
        if(a[now][x] < com[y]){
            tmp[++tmp_cnt] = a[now][x];
            x++;
        }
        else{
            tmp[++tmp_cnt] = com[y];
            y++;
        }
    }
    while(x <= n){
        tmp[++tmp_cnt] = a[now][x];
        x++;
    }
    while(y <= cnt){
        tmp[++tmp_cnt] = com[y];
        y++;
    }
    cnt = tmp_cnt;
    for(int i = 1;i <= cnt;i++){
        com[i] = tmp[i];
    }
    dfs(now + 1, val + c[now]);
    cnt = _cnt;
    for(int i = 1;i <= cnt;i++){
        com[i] = _com[i];
    }
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    //srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    /*n = 10000;
    m = 1000000;
    k = 10;
    for(int i = 1;i < n;i++){
        e[i].u = i;
        e[i].u2 = i + 1;
        e[i].w = 1LL * rand() * rand() % 1000000000LL;
    }*/
    for(int i = 1;i <= m;i++){
        /*e[i].u = rand() % (n - 1) + 2;
        e[i].u2 = rand() % (e[i].u - 1) + 1;
        e[i].w = 1LL * rand() * rand() % 1000000000LL;*/
        cin >> e[i].u >> e[i].u2 >> e[i].w;
    }
    sort(e + 1, e + m + 1);
    init_m();
    for(int i = 0;i < k;i++){
        cin >> c[i];
        //c[i] = 1LL * rand() * rand() % 1000000000LL;
        for(int j = 1;j <= n;j++){
            cin >> a[i][j].w;
            //a[i][j].w = 1LL * rand() * rand() % 1000000000LL;
            a[i][j].u = i + n + 1;
            a[i][j].u2 = j;
        }
        sort(a[i] + 1, a[i] + n + 1);
    }
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}
