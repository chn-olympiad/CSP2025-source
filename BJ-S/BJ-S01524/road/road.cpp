#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7,M = 1e6 + 5;
int f[N],n,m,k,ans = 0,l[N];
void build(){
    for (int i = 1;i <= n;i++) f[i] = i;
    return;
}

int father(int u){
    if (u == f[u]) return u;
    return f[u] = father(f[u]);
}
void put(int u,int v){
    int fu = father(u);
    int fv = father(v);
    f[fu] = fv;
    return;
}
struct Tu{
    int u,v,dis;
}g[M];
bool cmp(Tu x,Tu y){
    return x.dis < y.dis;
}
queue<int> q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    build();
    for (int i = 1;i <= m;i++){
        cin >> g[i].u >> g[i].v >> g[i].dis;
        //put(g[i].u,g[i].v);
    }
    int c;
    int cur = m;
    for (int i = 1;i <= k;i++){
        cin >> c;
        for (int j = 1;j <= n;j++){
            cin >> l[j];
        }
        for (int j = 1;j <= n;j++){
            for (int h = 1;h <= n && h != j;h++){
                g[++cur].u = j;
                g[cur].v = h;
                g[cur].dis = l[j] + l[h] + c;
            }
        }
    }
    for (int i = 1;i <= n;i++){
        f[i] = i;
    }
    sort(g + 1,g + cur + 1,cmp);
    for (int i = 1;i <= n - 1;i++){
        int u = g[i].u;
        int v = g[i].v;
        if (father(u) != father(v)){
            ans += g[i].dis;
            f[u] = v;
        }
    }
    cout << ans <<endl;
    return 0;
}
