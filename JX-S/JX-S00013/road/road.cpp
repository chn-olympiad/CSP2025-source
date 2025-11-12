#include<iostream>
#include<queue>
#include<vector>
using namespace stdl
int g[10010][10010];
void add(int x,int y,int w){
    g[x][y]=w;
    g[y][x]=w;
}
void dijkstra(){
priority_queue<pair<int,pair<int,int>>>dd;
dd.push(make_pair(0,make_pair(0,g[0].)));
while(!dd.empty()){
    int a=dd.top().first,b=dd.top().second.first,c=dd.top().second.second;
    dd.pop();
    for(int i=0;i<m;i++){
        int ans=0x3f3f3f3f;
        for(int j=0;j<n;j++){
            if(m1[j][g[i]]+m1[j][0]<ans){
            ans=m1[j][g[a]+1]+m1[j][0];
            }
        }
        if(dist[a]>dist[b]+c){
           dist[a]=dist[b]+c;
        }
        if(dist[a]>ans){
            dist[a]=ans;
        }
    }
}
}
int n,m,k,u,v,w,ans;
int main(){
    memset(dist,0,sizeof(dist));
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>m1[i][j];
       }
    }
    dijkstra();
    for(int i=0;i<m;i++){
            if(dist[i]!=0x3f3f3f3f){
                ans+=dist[i];
        }
    }
    cout<<ans;
return 0;
}
