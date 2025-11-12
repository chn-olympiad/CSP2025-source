//case A
//32pts
#include <bits/stdc++.h>
// #define int long long
using namespace std;

int n,m,k;
vector<pair<int,int> > mp[10005];
int c[11];
int a[11][10005];
bool bk=0;
bool bk2=0;

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    while (m--){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }
    for (int i=1;i<=k;i++){
        cin>>c[i];
        if (c[i]!=0) bk=1;
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            if (a[i][j]!=0) bk2=1;
        }
    }
    if (bk==0 and bk2==0){
        cout<<"0\n";
        return 0;
    }
    // if (k==0){
    //     //kruskal
    //     //zui4xiao3sheng1cheng2shu4

    // }
    return 0;
}