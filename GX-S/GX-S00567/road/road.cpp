#include <bits/stdc++.h>
using namespace std;

map<int,map<int,int>>a;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n+1;j++){
            cin >> a[i][j];

        }
    }
    return 0;

}
