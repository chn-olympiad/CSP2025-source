#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e4 + 15, M = 3e6 + 5;
int n, m, k, tcnt;
long long ans = 9e18;
int head[N], nxt[M], to[M], len[M], c[11], a[11][N], f[N];
bool w[11];

struct edge{
    int x, y, z;
} g[M];

bool operator<(edge a, edge b){
    return a.z < b.z;
}

void add(int x, int y, int z){
    to[++tcnt] = y;
    len[tcnt] = z;
    nxt[tcnt] = head[x];
    head[x] = tcnt;
}

int find(int x){
    if (f[x] != x){
        f[x] = find(f[x]);
    }
    return f[x];
}

void merge(int x, int y){
    f[find(y)] = find(x);
}

bool chkpts(){
    for (int i = 1; i <= k; i++){
        if (c[i]){
            return 0;
        }
        bool flag = 0;
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 0){
                flag = 1;
                break;
            }
        }
        if (!flag){
            return 0;
        }
    }
    return 1;
}

void solve1(){
    int cur = 0;
    for (int x = 1; x <= n; x++){
        for (int I = head[x]; I; I = nxt[I]){
            int y = to[I], z = len[I];
            if (x > y){
                continue;
            }
            g[++cur] = {x, y, z};
        }
    }
    sort(g + 1, g + cur + 1);
    for (int i = 1; i <= n; i++){
        f[i] = i;
    }
    int cnt = 0; long long res = 0;
    for (int i = 1; i <= cur; i++){
        int x = g[i].x, y = g[i].y, z = g[i].z;
        if (find(x) != find(y)){
            merge(x, y);
            cnt++, res += z;
            if (cnt == n - 1){
                break;
            }
        }
    }
    cout << res;
}

void dfs(int x){
    if (x > k){
        int cur = 0;
        for (int x = 1; x <= n; x++){
            for (int I = head[x]; I; I = nxt[I]){
                int y = to[I], z = len[I];
                if (x > y){
                    continue;
                }
                g[++cur] = {x, y, z};
            }
        }
        int cnt = 0; long long res = 0;
        for (int i = 1; i <= k; i++){
            if (w[i]){
                cnt--, res += c[i];
                for (int j = 1; j <= n; j++){
                    g[++cur] = {n + i, j, a[i][j]};
                }
            }
        }
        sort(g + 1, g + cur + 1);
        for (int i = 1; i <= n + k; i++){
            f[i] = i;
        }
        for (int i = 1; i <= cur; i++){
            int x = g[i].x, y = g[i].y, z = g[i].z;
            if (find(x) != find(y)){
                merge(x, y);
                cnt++, res += z;
                if (cnt == n - 1){
                    break;
                }
            }
        }
        ans = min(ans, res);
        return;
    }
    w[x] = 0;
    dfs(x + 1);
    w[x] = 1;
    dfs(x + 1);
}

void solve2(){
    dfs(1);
    cout << ans;
}

void solve3(){
    int cur = 0;
    for (int x = 1; x <= n; x++){
        for (int I = head[x]; I; I = nxt[I]){
            int y = to[I], z = len[I];
            if (x > y){
                continue;
            }
            g[++cur] = {x, y, z};
        }
    }
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            g[++cur] = {n + i, j, a[i][j]};
        }
    }
    sort(g + 1, g + cur + 1);
    for (int i = 1; i <= n + k; i++){
        f[i] = i;
    }
    int cnt = 0; long long res = 0;
    for (int i = 1; i <= cur; i++){
        int x = g[i].x, y = g[i].y, z = g[i].z;
        if (find(x) != find(y)){
            merge(x, y);
            cnt++, res += z;
            if (cnt == n + k - 1){
                break;
            }
        }
    }
    cout << res;
}

void solve4(){
    for (int t = 1; t <= n; t++){
        w[t] = 1;
        int cur = 0;
        for (int x = 1; x <= n; x++){
            for (int I = head[x]; I; I = nxt[I]){
                int y = to[I], z = len[I];
                if (x > y){
                    continue;
                }
                g[++cur] = {x, y, z};
            }
        }
        int cnt = 0; long long res = 0;
        for (int i = 1; i <= k; i++){
            if (w[i]){
                cnt--, res += c[i];
                for (int j = 1; j <= n; j++){
                    g[++cur] = {n + i, j, a[i][j]};
                }
            }
        }
        sort(g + 1, g + cur + 1);
        for (int i = 1; i <= n + k; i++){
            f[i] = i;
        }
        for (int i = 1; i <= cur; i++){
            int x = g[i].x, y = g[i].y, z = g[i].z;
            if (find(x) != find(y)){
                merge(x, y);
                cnt++, res += z;
                if (cnt == n - 1){
                    break;
                }
            }
        }
        w[t] = (res < ans);
        ans = min(ans, res);
    }
    cout << ans;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int x, y, z; cin >> x >> y >> z;
        add(x, y, z), add(y, x, z);
    }
    for (int i = 1; i <= k; i++){
        cin >> c[i];
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if (k == 0){
        solve1();
    }
    else if (k <= 5){
        solve2();
    }
    else if (chkpts()){
        solve3();
    }
    else{
        solve4();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}