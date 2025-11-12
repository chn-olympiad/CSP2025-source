#include <bits/stdc++.h>
using namespace std;
int n, m, kk, u, v, w, a[10005][10005], c, r[10005], vv[100005], as=1e9;
void f(int dx, int p, int s){
    if (s==n){
        as = min(as, p);
        return ;
    }
    for (int i=1;i<=n;i++){
        if (dx==i||vv[i]) continue;
        vv[i] = 1;
        f(i,p+a[dx][i],s++);
        vv[i] = 0;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> kk;
    for (int i=1;i<=m;i++){
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    for (int i=1;i<=kk;i++){
        cin >> c;
        for (int j=1;j<=n;j++) cin >> r[j];
        for (int j=1;j<=n;j++) for (int k=j+1;k<=n;k++){
            if (!a[j][k]){
                a[j][k] = r[j]+r[k];
                a[k][j] = r[j]+r[k];
            }
            a[j][k] = min(a[j][k],r[j]+r[k]);
            a[k][j] = min(a[j][k],r[j]+r[k]);
        }
    }
    vv[1] = 1;
    f(1, 0, 1);
    cout << as;
    return 0;
}
