#include<bits/stdc++.h>
#define MAXN 2000005
using namespace std;
int n,m,k,h[MAXN<<1],to[MAXN<<1],nxt[MAXN<<1],val[MAXN<<1],cnt=0,c[15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int u,v,w,i=1;i<=m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=k;i++) {
        cin>>c[k];
        for(int j=1;j<=n;j++) {
            int a;
            cin>>a;
            add(n+i,j,a);
            add(j,n+1,a);
        }
    }

}
