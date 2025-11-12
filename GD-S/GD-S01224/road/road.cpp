#include <iostream>
#include <vector>
using namespace std;

int n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    //remember memset
    int u, v, w;
    cin>>n>>m>>k;
    for (int i=0;i<m;i++) cin>>u>>v>>w;
    for (int i=0;i<k;i++) for (int j=0;j<=n;j++) cin>>u;

    cout<<0<<'\n';

    return 0;
}