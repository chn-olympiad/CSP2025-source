#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
struct edge{
    int u,v,w;
    bool operator < (const edge &rhs)const{
        return w<rhs.w;
    }
}e[M+N*K];
int c[K];
bool bld[K];
int fa[N+K];
int find(int x){
    return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
int in[N+K];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    int cnt=m;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int w;scanf(" %d",&w);
            edge tmp={n+i,j,w+c[i]};
            e[++cnt]=tmp;
        }
    }
    sort(e+1,e+cnt+1);
    //for(int i=1;i<=cnt;i++)cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
    int sum=0,ans=0;
    vector<edge>ve;
    for(int i=1;i<=n+k;i++)fa[i]=i; 
    for(int i=1;i<=cnt;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(u>n){
            if(bld[u-n])w-=c[u-n];
            else bld[u-n]=1;
        }
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            fa[fv]=fu;
            ve.push_back(e[i]);
            sum++;
            if(u>n)in[u-n]++;
            ans+=w;
        }
        if(sum==n+k-1)break;
    }
    //cout<<ans<<'\n';
    for(int i =0 ;i<ve.size();i++){
        edge ed=ve[i];
        if(ed.u>n && in[ed.u-n]==1)ans-=ed.w;
    }
    cout<<ans<<'\n';
    return 0;
}
