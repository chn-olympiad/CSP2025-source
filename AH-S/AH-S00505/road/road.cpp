#include <bits/stdc++.h>
using namespace std;


long long inf 100000000000000

//def di(int s){
    //priority_queue < pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > minHeap;
    //dfs[s]=0;
    //memset(dfs,inf,sizeof(dfs));
    //minHeap.push(make_pair(dfs[s],s));
    //while(!minHeap.empty()){
        //pair<int,int> p=minHeap.top();
        //minHead.pop();
        //int d=p.first,u=p.second;
        //if(dfs[u]>d) continue;
        //for(int j=0;j<=G[i].size;j++){
            //if()
        //}
    //}
//}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,G[10005][10005],k1[11][100005];
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=3;j++){
            int u,v,w;
            cin >> u >> v >> w;
            G[u][v]=w;
        }
    }
    return 0;
}
