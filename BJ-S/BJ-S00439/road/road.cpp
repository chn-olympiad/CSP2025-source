#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+1,M=1e6+1;
int n,m,k,cost[11],a[11][N],fa[N+15],top=0,res=0;
struct oneEdge{
    int u,v,w;
    bool operator<(const oneEdge&alp)const{
        return this->w<alp.w;
    }
}at[M],in[M],e[N];
void init(int n){iota(fa+1,fa+n+1,1LL);}
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
bool merge(int u,int v){
    int fx=find(u),fy=find(v);
    fa[fx]=fy;
    return fx!=fy;
}
int kksk(int r){
    init(n+k);
    int ans=0;
    sort(in+1,in+m+1);
    for(int i=1;i<=m;i++){
        if(merge(in[i].u,in[i].v)){
            ans+=in[i].w;
            r--;
            e[++top]={in[i].u,in[i].v,in[i].w};
        }
        if(r==1)break;
    }
    return ans;
}
int getans(int g){
    init(n+k);
    int ans=0;
    sort(at+1,at+res+1);
    for(int i=1;i<=res;i++){
        if(merge(at[i].u,at[i].v)){
            ans+=at[i].w;
        }
        if(ans>g)break;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>in[i].u>>in[i].v>>in[i].w;
    }
    int ans=kksk(n);
    for(int i=1;i<=k;i++){
        cin>>cost[i];
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    for(int i=1;i<(1<<k);i++){
        int cnt=0;
        for(int j=1;j<n;j++){
            at[j]=e[j];
        }
        res=n-1;
        for(int j=1;j<=k;j++){
            if(i&(1<<j-1)){
                cnt+=cost[j];
                for(int l=1;l<=n;l++){
                    at[++res]={n+j,l,a[j][l]};
                }
            }
        }
        ans=min(ans,getans(ans-cnt)+cnt);
    }
    cout<<ans<<'\n';
    return 0;
}