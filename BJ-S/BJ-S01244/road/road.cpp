#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
struct node{
    int u, v, w, type;
    bool operator <(const node& x) const{
        return w < x.w;
    }
};

vector<node> g;
int gz[20][1010];
int fa[1010];
inline int read(){
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x;
}
int fnd(int x){
    if (fa[x] == x) return x;
    return fa[x] = fnd(fa[x]);
}
void merg(int x, int y){
    if (fnd(x) == fnd(y)) return;
    fa[y] = fa[x];
}

signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++){
        int u = read(), v = read(), w = read();
        g.push_back({u, v, w, 0});
        g.push_back({v, u, w, 0});
    }

    int totc = 0;
    for (int i = 1; i <= k; i++){
        gz[i][0] = read();
        totc += gz[i][0];
        for (int j = 1; j <= n; j++){
            gz[i][j] = read();
        }
    }

    if (totc == 0){
        for (int xz = 1; xz <= k; xz++){
            for (int u = 1; u <= n; u++){
                for (int v = u+1; v <= n; v++){
                    g.push_back({u, v, gz[xz][u]+gz[xz][v], 1});
                    g.push_back({v, u, gz[xz][u]+gz[xz][v], 1});
                }
            }
        }
        sort(g.begin(), g.end());
        int ans = 0;
        for (auto e:g){
            int cu = min(e.u, e.v), cv = max(e.u, e.v);
            if (fnd(cu) == fnd(cv)) continue;
            merg(cu, cv);
            ans += e.w;
        }
        cout << ans;
    }

    return 0;
}
