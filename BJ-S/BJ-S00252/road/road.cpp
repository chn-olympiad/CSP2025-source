#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::priority_queue;
#define MAXN 10000
#define MAXM 1000003
#define MAXK 13
struct edge{
    int v,w;
};
vector<edge> e[MAXN+MAXK];
int n,m,k,cnt;
long long c[MAXK];
bool vis[MAXN+MAXK],flag[MAXK];
struct node{
    int x;
    long long dis;
    bool operator>(const node& a)const{return (dis>a.dis);}
};
int sol(int s){
    long long sum=0;
    priority_queue<node, vector<node>, std::greater<node> > q;
    q.push({s,0});
    while(!q.empty()){
        int x=q.top().x,y=q.top().dis;
        if(vis[x]){q.pop();continue;}
        vis[x]=1;
        sum+=y;
        if(x<MAXN)  cnt++;
        // cout<<"rp"<<x<<' '<<' '<<sum<<'-'<<y<<' '<<cnt<<endl;
        if(cnt>=n){
            q.pop();
            break;
        }
        q.pop();
        for(int i=0;i<e[x].size();i++){
            int v=e[x][i].v;
            long long nxt=e[x][i].w;
            if(vis[v])   continue;
            if(v>MAXN){
                if(!flag[v-MAXN]) nxt+=c[v-MAXN],flag[v-MAXN]=true;
                q.push({v,nxt});
            } else {
                q.push({v,nxt});
            }
        }
    }
    return sum;
}
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
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            e[i+MAXN].push_back({j,w});
            e[j].push_back({i+MAXN,w});
        }
    }
    cout<<sol(1)<<endl;
    return 0;
}
