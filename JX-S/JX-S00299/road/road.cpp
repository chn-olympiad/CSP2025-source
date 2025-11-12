#include<bits/stdc++.h>
using namespace std;
const int M=1e4+5;
int ma[M][M];
queue<int> que;
int no[M];
int n,m,k;
int ne[12][M];
bool tr[M];
void bfs(){
    while(!que.empty()){
        for(int i=1;i<=n;i++){
            if(ma[i][que.front()]!=0&&!tr[i]){
                no[i]=no[que.front()]+ma[i][que.front()];
                tr[i]=1;
                que.push(i);
            }
        }
        que.pop();
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ma[u][v]=w;
    }
    que.push(1);
    bfs();
    cout<<no[m];
    return 0;
}
