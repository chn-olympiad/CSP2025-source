#include <bits/stdc++.h>
using namespace std;
#define int long long

int par[10015];

int findp(int x){
    if(par[x] == x) return x;
    return par[x] = findp(par[x]);
}

void merge(int x, int y){
    x = findp(x);
    y = findp(y);
    par[y] = x;
}

int32_t main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    bool A=1;
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>>edge[10005];
    vector<tuple<int, int, int>>paths;
    for(int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        paths.push_back({w, u, v});
        edge[u].push_back({w, v});
        edge[v].push_back({w, u});
    }
    int c[15]; vector<int>a[15];
    for(int i=1; i<=k; i++){
        cin >> c[i];
        if(c[i] != 0) A=0;
        a[i].push_back(0);
        for(int j=1; j<=n; j++){
            a[i].push_back(0);
            cin >> a[i][j];
            if(a[i][j] != 0) A=0;
        }
    }
    if(k==0){
        int ans = 0;
        for(int i=1; i<=n; i++){
            par[i] = i;
        }
        if(A){
            for(int i=1; i<=k; i++){
                par[n+i] = n+i;
                for(int j=1; j<=n; j++){
                    paths.push_back({a[i][j], n+i, j});
                }
            }
        }
        sort(paths.begin(), paths.end());
        for(int i=0; i<m; i++){
            int w = get<0>(paths[i]);
            int u = get<1>(paths[i]);
            int v = get<2>(paths[i]);
            if(findp(u) != findp(v)){
                merge(u, v);
                ans += w;
            }
        }
        cout << ans;
    }else if(A){
        cout << 0;
    }

    return 0;
}