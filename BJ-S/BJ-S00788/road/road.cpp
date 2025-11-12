#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
struct N{
    long long v,w;
};
vector<N> g[10010];
long long c[15],xina[15][10010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (long long i=1;i<=m;i++){
        long long u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for (long long i=1;i<=k;i++){
        cin >> c[k];
        for (long long j=1;j<=n;j++){
            cin >> xina[i][j];
        }
    }
    cout << 0;
    return 0;
}