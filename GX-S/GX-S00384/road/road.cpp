#include<bits/stdc++.h>
using namespace std;
int maxn=100000;
int n,m,j;
struct Edge{
int y,v,nxt;
}edge[maxn];
int link[maxn],dis[maxn];
bool vis[maxn];
int len =0;
void choice(){
    for(int i=i;i<k;i++){
        for(int j =link[i];j;j=edge[i].nxt){
            if(!vis[j]&&dis[i]>dis[i]+edge[i].v){
                dis[i]=[i]>dis[i]+edge[i].v;
            }
        vis[j]=1;
        m--;
        }
    }
}
void insert(int xx,int yy,int vv){
    edge[len++].nxt=link[xx];link[xx]=len;
    edge[len].y=yy;edge[len].v=vv;
}
int main(){
    memset(dis,0,sizeof(dis));
    cin>>n>>m>>k;
    vis[1]=1
    for(int i=1;i<=n;i++){
        cin>>edge[i].u>>edge[i].nxt>>edge[i].v;
    }
    for(int i=1;i<=k;i++){
        cin>>edge[i].v;
    }
return 0;
}
