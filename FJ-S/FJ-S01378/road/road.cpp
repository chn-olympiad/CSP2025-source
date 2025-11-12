#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N=1e4+5,M=1e6+5,K=10+5;
int n,m,k,cnt,c[K];
struct edg{int u,v,w;}e[N*K+M];
namespace ust{
    int fa[N+K];
    void init(){
        for(int i=1;i<=n+k;i++)fa[i]=i;
    }
    int fd(int u){
        int k=u;
        while(fa[k]!=k)k=fa[k];
        return fa[u]=k;
    }
    bool mg(int u,int v){
        u=fd(u);v=fd(v);
        if(u==v)return 0;
        fa[u]=v;return 1;
    }
}
int main(){
    i64 ans=1e16;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;int sz=1<<k;
    for(int i=1,u,v,w;i<=m;i++)
        cin>>u>>v>>w,e[++cnt]={u,v,w};
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1,x;j<=n;j++)cin>>x,e[++cnt]={j,i+n,x};
    }sort(e+1,e+cnt+1,[](edg x,edg y){
        return x.w<y.w;
    });
    for(int t=0;t<sz;t++){
        i64 tot=0,ct=n-1;
        for(int j=0;j<k;j++)
            if((t>>j)&1)tot+=c[j+1],ct++;
        ust::init();
        for(int i=1;i<=cnt && ct;i++){
            if(e[i].v>n && ((t>>(e[i].v-n-1))&1)==0)continue;
            bool x=ust::mg(e[i].u,e[i].v);
            if(x)ct--,tot+=e[i].w;
            //cerr<<t/2<<' '<<(t&1)<<' '<<tot<<endl;
        }       
        if(!ct)ans=min(ans,tot);
    }
    cout<<ans<<endl;
}