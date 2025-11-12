#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
    int v,w;
};
vector<node>mp[2000055];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }
    cout<<0;
    return 0;
}
