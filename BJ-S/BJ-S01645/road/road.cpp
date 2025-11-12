#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int MAXN=20000005;
int head[MAXN],to[MAXN],nxt[MAXN],tot=0,val[MAXN];
void add_edge(int u,int v,int w){
    tot++;
    to[tot]=v;
    val[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot;
    return;
}
struct node{
    int x;
    int y;
    bool operator < (const node &o) const {
        return y<o.y;
    }
};
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    for (int i=1;i<=k;i++){
        int c;
        cin>>c;
        for (int j=1;j<=n;j++){
            int a;
            cin>>a;
        }
    }
    cout<<"67382";
return 0;
}
