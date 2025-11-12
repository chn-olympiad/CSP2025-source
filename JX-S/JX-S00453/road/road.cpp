#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
struct r{
    int another;
    int money;
};
vector<r> e[N];
int village[15][N];
int v_m[15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    bool f=true;
    for(int i=1;i<=k;i++){
        cin>>v_m[i];
        if(v_m[i]!=0)f=false;
        for(int j=1;j<=n;j++){
            cin>>village[i][j];
            if(village[i][j]!=0)f=false;
        }
    }
    if(f){
        cout<<0;
        return 0;
    }
    return 0;
}
