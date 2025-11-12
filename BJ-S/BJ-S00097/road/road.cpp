#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5, M=1e4+5;
long long n, m, k, c[M], cnt, l[20][M], dis[M], ans, vis[M];
int tt[N], q[N], ne[N], h[N], idx;
void add(int a, int b, int c){
    tt[++idx]=b;
    q[idx]=c;
    ne[idx]=h[a];
    h[a]=idx;
}
void prim(){
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    for(int i=1;i<=n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(t==-1&&!vis[j]) t=j;
            else if(!vis[j]&&dis[j]<dis[t]){
                t=j;
            }
        }
        ans+=dis[t];
        vis[t]=1;
        for(int j=h[t];j;j=ne[j]){
            int v=tt[t];
            int w=q[t];
            dis[v]=min(dis[v],dis[t]+w);
        }
        for(int j=1;j<=n;j++){
            if(vis[j]) continue;
            for(int kk=1;kk<=k;kk++){
                dis[j]=min(dis[j],dis[t]+l[kk][t]+l[kk][j]);
            }
        }
    }
    return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=k;i++){
        cin >> c[i];
        for(int j=1;j<=n;j++){
            cin >> l[i][j];
        }
    }
    prim();
    cout << ans;
    return 0;
}
