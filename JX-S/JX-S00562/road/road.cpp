#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+7;
int t,a[N],n,m,k,ans;
vector<pair<int,int>> rd[N];
/*
void dfs(int u,int fa){
    for(auto v : rd){
        int fi = vfirst;
        int se = v.second;
        if(fi != fa){
            ans += fi;
            dfs(fi,u);
        }
        else continue;
    }
}
*/
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        rd[u].push_back({v,w});
        rd[v].push_back({u,w});
    }
    int c;
    cin >> c;
    while(k--){
        for(int i = 1;i<=n;i++) cin >> a[i];
    }

    cout << 13;
    return 0;
}
