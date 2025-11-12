#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n=0,m=0,k=0,x=0,sum=0;
vector<vector<int>>tu{0};
vector<int>tu_sco{0};
queue<int>pos;
vector<bool>visited{false};
void addtu(int u,int v){
tu[v].push_back(u);
tu[u].push_back(v);
}
void bfs(int strat){
    visited[strat]=true;
    pos.push(strat);
    while(!pos.empty()){
        for(int x:tu[x]){
            int minn;
            sum+=min(tu_sco[x],minn);
            if(!visited[x]){
                visited[x]=true;
                pos.push(x);
            }
        }
    }
}
int main()
{
    freopen("road.in""r",stdin);
    freopen("road.out""w",stdout);

cin>>n>>m>>k;
for(int i=1;i<=m;i++){
    int u=0,v=0,sco=0;
    cin>>u>>v>>sco;
    addtu(u,v);
    tu_sco.push_back(sco);}

for(int j=m+1;j<=(m+1+k);j++){
    int itcost=0;
    cin>>itcost;
    for(int i=1;i<=(n+1);i++){
        int ccso=0;
        cin>>ccso;
        addtu(m+j+1,i);
        tu_sco.push_back((itcost+ccso));
    }
}
    bfs(1);
    cout<<sum<<endl;
    fclose("road.in");
    fclose("road.out");
    return 0;
}
