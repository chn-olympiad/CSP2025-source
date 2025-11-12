#include <bits/stdc++.h>
#define rep(a,b,c) for (int (a)=(b); (a)<=(c); ++(a))
typedef long long ll;
using namespace std;
const int N=1e4, M=1e6+5, K=10+5;
struct Edge {
    int u, v, w;
    operator<(const Edge D)const{
        return w > D.w;
    };
} ed[M];
int n, m, k, c[K], a[K][N], flag[M+N], par[M+N], cnt, ans;

priority_queue<Edge> q;

int fnd(int x){
    return (par[x] == x) ? x : (par[x]=fnd(par[x]));
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    rep(i, 1, m){
        int u, v, w;
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
        q.push(ed[i]);
    }
    rep(i, 1, k){
        cin >> c[i];
        rep(j, 1, n){
            cin >> a[i][j];
            q.push({n+i, j, a[i][j]});
        }
    }
    rep(i, 1, n+k)
        par[i] = i;

    while (!q.empty()){
        Edge i = q.top(); q.pop();
        if (i.u > n && (!flag[i.u-n]) && i.w == a[i.u-n][i.v]){
            q.push({i.u, i.v, i.w+c[i.u-n]});
            continue;
        }
        if (i.u > n && flag[i.u-n] && i.w != a[i.u-n][i.v])
            i.w -= c[i.u-n];
        if (fnd(i.u) == fnd(i.v)) continue;

        int u = i.u, v=i.v, w=i.w;
        ans += w;
        if (u > n){
            flag[u-n]=1;
        }

        par[u] = v;
        if (fnd(u)<=n && fnd(v)<=n)
            cnt ++;
        if (cnt == n)
            break;
    }
    cout << ans;
    return 0;
}

