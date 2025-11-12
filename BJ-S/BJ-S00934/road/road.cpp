#include <bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e4+11;
int n,m,k,c[15],a[15][N];
vector <pii> g[N];
priority_queue <pii> q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    rep(i,1,k){
        scanf("%d",c+i);
        int flag=1;
        rep(j,1,n){
            scanf("%d",a[i]+j);
            if(a[i][j]!=0)flag=0;
        }
        if(flag=1&&c[i]==0){
            puts("0");
            return 0;
        }
    }
    return 0;
}
