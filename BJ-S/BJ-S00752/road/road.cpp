#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,c[15],a[15][10005],fa[1000005];
struct nd{int u,v,w; bool operator <(nd b) const{return w<b.w;}} e[2000005];

int getfa(int u){return u==fa[u]?fa[u]:fa[u]=getfa(fa[u]);}

int fun(int u,int fa){
    for(int i=1;i<=n;i++);
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k; int mm=m;
    for(int i=1,a,b,c;i<=m;i++) cin >> a >> b >> c, e[i]={a,b,c};
    for(int i=1;i<=k;i++){
        cin >> c[i];
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    int ans=0;
    sort(e+1,e+1+m);
    for(int i=1;i<=m;i++){
        if(fa[i]==i) continue;
        ans+=e[i].w; fa[e[i].u]=fa[e[i].v];
    }
    cout << ans;
    return 0;
}
