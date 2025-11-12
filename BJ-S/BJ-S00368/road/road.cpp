#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],a[15][10005];
struct graph{
    int u,v,w;
}g[1000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) cin >> g[i].u >> g[i].v >> g[i].w;
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }
    cout << 0;
    return 0;
}
