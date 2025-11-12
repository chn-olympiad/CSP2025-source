#include <>bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >>n >>m >>k;
    vector<vector<int>> g(n,vector<int>(n,-1));
    vector<int> c()
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u][v] = w;
    }
}
