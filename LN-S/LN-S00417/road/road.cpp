#include<bits/stdc++.h>
using namespace std;
int n , m , k ;
struct edge{
    int to , l ;
    edge(int tto , int ll){
        to=tto,l=ll;
    }
};
vector<edge> edges[10030] ;
int c[15] ;
int q[100100] , f , r ;
long long cost[10030] , reses[10030] ;
long long ans=1e18;
bool p[10030] , b[10030] ;
long long calc_ans=0LL;
long long dfs(int x){
    if(x==-1) return -2e9;
    b[x]=true;
    int mnans=-1 , mnnum=2e9 ;
    for(auto y:edges[x]){
        if(b[y.to]==false && p[y.to]==true){
            if(y.l<mnnum) mnnum=y.l,mnans=y.to;
        }
    }
    return 1LL*mnnum+dfs(mnans);
}
long long calc(){
    calc_ans=0LL;
    memset(b,false,sizeof(b));
    return dfs(1);
}
void solve(int x){
    if(x==n+k+1){
        long long res=0LL;
        for(int i=n+1;i<=n+k;i++){
            if(p[i]==true) res+=c[i-n];
        }
        ans=min(ans,res+calc());
        return ;
    }
    p[x]=true;
    solve(x+1);
    p[x]=false;
    solve(x+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u , v , w ;
        scanf("%d%d%d",&u,&v,&w);
        edges[u].push_back(edge(v,w));
        edges[v].push_back(edge(u,w));
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            edges[n+i].push_back(edge(j,x));
            edges[j].push_back(edge(n+i,x));
        }
    }
    for(int i=1;i<=n;i++){
        p[i]=true;
    }
    solve(n+1);
    printf("%lld",ans);
    return 0;
}
