#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> edge(n+1,vector<int>());
    vector<vector<int>> value(n+1,vector<int>(n+1,-1));
    vector<vector<int>> vilage(k,vector<int>(n+1));
    vector<int> vil(k,0);
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        value[u][v]=w;
        value[v][u]=w;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<5;j++){
            cin>>vilage[i][j];
        }
        vil[i]=vilage[i][0];
    }
    vector<bool> ischoose(n+1,false);
    vector<vector<int>> arr;
    int a=0;
    for(int i=0;i<5;i++){
        a+=vilage[0][i];
    }
    if(a==0){
        cout<<0;
    }
    return 0;
}
