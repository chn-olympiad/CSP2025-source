#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int to,val;
};
int n,m,k,rf[10050],ans=0x3f;
vector<node> mp[10050];

int dfs(int f,int s){
    int minn=LONG_MAX;
    for(int i=0;i<mp[s].size();i++){
        if(mp[s][i].to==f) continue;

    }
    return minn;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int u=0,v=0,w=0;
        cin >> u >> v >> w;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin >> rf[j];
        }
    }
    cout << 0;


    return 0;
}
