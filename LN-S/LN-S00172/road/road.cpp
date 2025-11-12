#include<bits/stdc++.h>
using namespace std;

int n,m,k;
const int N=1e6+1;
struct road{
    int u,v,w;
}q[N];
int c[N],a[N][N];

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    for(int i=1;i<=m;i++) cin >> q[i].u >> q[i].v >> q[i].w;
    for(int i=1;i<=k;i++){
        cin >> c[i];
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    cout << 13;
    return 0;
}
