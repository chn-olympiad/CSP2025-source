//Dijkstra
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10,M = 1e6 + 10;
int idx;
int fa[N],visit[N],a[N];
int to[N << 1],ne[N << 1],pre[N << 1],weight[N << 1];

int Find(int x){
    if(fa[x] == x) return x;
    else fa[x] = Find(fa[x]);
}

bool Union(int x,int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx != fy){
        fa[fx] = fy;
        return true;
    }
    return false;
}

void build(int u,int v,int w){
    to[++idx] = v;
    ne[idx] = pre[u];
    pre[u] = idx;
    weight[idx] = w;
}



int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    int u,v,w;
    for(int i = 1;i<=m;i++){
        cin >> u >> v >> w;
        build(u,v,w);
        build(v,u,w);
    }
    for(int i = m + 1;i <= m + k;i++){
        cin >> a[i];
        for(int j = 1;j <= n;j++){
            build(j,i,)
        }
    }
    for(int i = 1;i<=n;i++) fa[i] = i;
    return 0;
}
