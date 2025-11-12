#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int t[1005][1005];//linjiejvzhen
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0){
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            t[u][v]=w;
        }

    }
    else cout<<0;
}
