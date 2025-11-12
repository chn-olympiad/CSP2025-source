#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,c[10015],cnt,fa[10015],cst,minn = LONG_LONG_MAX;
bool open[10015];
struct edge{
    int u,v,w;
    bool operator < (const edge &x) const{
        return w < x.w;
    }
}e[1100005];
int findx(int x){
    return x == fa[x] ? x : fa[x] = findx(fa[x]);
}
int mst(){
    int N = 0,ans = 0,edgecnt = 0;
    for (int i = 1;i <= n + k;i++) if (open[i]){
        N++;
        fa[i] = i;
    }
    for (int i = 1;i <= cnt;i++) if (open[e[i].u] && open[e[i].v]){
        int fx = findx(e[i].u),fy = findx(e[i].v);
        if (fx != fy){
            edgecnt++;
            fa[fx] = fy;
            ans += e[i].w;
        }
        if (edgecnt == N - 1) return ans;
    }
}
void dfs(int x){
    if (x > n + k){
        minn = min(minn,cst + mst());
        return;
    }
    dfs(x + 1);
    open[x] = true;
    cst += c[x];
    dfs(x + 1);
    cst -= c[x];
    open[x] = false;
}
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++) open[i] = true;
    for (int i = 1;i <= m;i++) cin >> e[i].u >> e[i].v >> e[i].w;
    cnt = m;
    for (int i = 1;i <= k;i++){
        cin >> c[n + i];
        for (int j = 1;j <= n;j++){
            cnt++;
            e[cnt].u = n + i;
            e[cnt].v = j;
            cin >> e[cnt].w;
        }
    }
    sort(e + 1,e + cnt + 1);
    dfs(n + 1);
    cout << minn;
    return 0;
}