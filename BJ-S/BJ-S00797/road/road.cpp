#include<bits/stdc++.h>
using namespace std;
const int N = 1e4;
struct cost{
    int selfc,otherc[N];
}c[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    vector< vector< pair<int,int> > > mapp;
    mapp.resize(n + 1);
    for(int i = 0;i < m;i ++){
        int u,v,w;
        cin >> u >> v >> w;
        mapp[u].emplace_back(v,w);
    }
    bool flag = true;
    for(int i = 0;i < k;i ++){
        cin >> c[i].selfc;
        if(flag) if(c[i].selfc != 0) flag = false;
        for(int j = 0;j < n;j ++){
            int ccc;
            cin >> ccc;
            c[i].otherc[j] = ccc;
            if(flag) if(ccc != 0) flag = false;
        }
    }
    if(flag) cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
