#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(u) ((u)&-(u))
using namespace std;
const int N=10020,M=1000020,K=20,T=1050;
struct EDGE{
    int u,v,w;
    inline bool operator<(const EDGE&rhs)const{return w!=rhs.w?w<rhs.w:(u!=rhs.u?u<rhs.u:v<rhs.v);}
    inline bool operator>(const EDGE&rhs)const{return w!=rhs.w?w>rhs.w:(u!=rhs.u?u>rhs.u:v>rhs.v);}
}edge[K][N],sed[M],tmp[N<<1],tmp2[M<<1];vector<EDGE>vc[T];
int fa[N],n,kk,m,_2[N],lg[N],id[N],cost[N],val[K][N];ll dp[N],ans;

inline int fd(int u){return u==fa[u]?u:fa[u]=fd(fa[u]);}

inline ll solve(int lst,int u){
    int nw=lst|_2[u];ll res=0;
    for(int i=1;i<=n+kk;i++)fa[i]=i;
    int p1=1,p2=0,p3=0;
    while(p1<=n&&p2<vc[lst].size()){
        if(edge[u][p1]<vc[lst][p2])tmp[++p3]=edge[u][p1++];
        else tmp[++p3]=vc[lst][p2++];
    }
    while(p1<=n)tmp[++p3]=edge[u][p1++];
    while(p2<vc[lst].size())tmp[++p3]=vc[lst][p2++];
    for(int i=1;i<=p3;i++){
        int u=fd(tmp[i].u),v=fd(tmp[i].v);
        if(u==v)continue;
        res+=tmp[i].w;fa[u]=v;
        //cout<<"!!!!"<<tmp[i].u<<','<<tmp[i].v<<"; "<<tmp[i].w<<endl;
        vc[nw].pb(tmp[i]);
    }
    //cout<<"\n\n\n\n\n\n\n\n";
    return res;
}
/*inline ll solve3(int lst,int u){
    int nw=lst|_2[u];ll res=0;
    for(int i=1;i<=n+kk;i++)fa[i]=i;
    int p1=1,p2=0,p3=0;
    while(p1<=n&&p2<vc[lst].size()){
        if(edge[u][p1]<vc[lst][p2])tmp[++p3]=edge[u][p1++];
        else tmp[++p3]=vc[lst][p2++];
    }
    for(auto i:vc[lst]){
        cout<<"\t???"<<i.u<<' '<<i.v<<": "<<i.w<<endl;
    }
    while(p1<=n)tmp[++p3]=edge[u][p1++];
    while(p2<vc[lst].size())tmp[++p3]=vc[lst][p2++];
    for(int i=1;i<=p3;i++){
        int u=fd(tmp[i].u),v=fd(tmp[i].v);
        if(u==v)continue;
        res+=tmp[i].w;fa[u]=v;
        cout<<"!!!!"<<tmp[i].u<<','<<tmp[i].v<<"; "<<tmp[i].w<<endl;
        vc[nw].pb(tmp[i]);
    }
    return res;
}


inline void solve2(){
    int sz2=0;
    for(int i=1;i<=m;i++)tmp2[++sz2]=sed[i];
    for(int i=1;i<=kk;i++)for(int j=1;j<=n;j++)tmp2[++sz2]=edge[i][j];
    sort(tmp2+1,tmp2+1+sz2);for(int i=1;i<=n+kk;i++)fa[i]=i;
    int res=0;
    for(int i=1;i<=sz2;i++){
        int u=fd(tmp2[i].u),v=fd(tmp2[i].v);
        if(u==v)continue;
        fa[u]=v;res+=tmp2[i].w;
        cout<<tmp2[i].u<<','<<tmp2[i].v<<endl;
    }
    cout<<res<<endl;
}
*/
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>kk;_2[1]=lg[1]=1;
    for(int i=2;i<=kk;i++)lg[_2[i]=_2[i-1]<<1]=i;
    for(int i=1;i<=m;i++){
        cin>>sed[i].u>>sed[i].v>>sed[i].w;
    }sort(sed+1,sed+1+m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=fd(sed[i].u),v=fd(sed[i].v);
        if(u==v)continue;
        ans+=sed[i].w;
        fa[u]=v;vc[0].pb(sed[i]);
    }
    for(int i=1;i<=kk;i++){
        cin>>cost[i];
        for(int j=1;j<=n;j++)cin>>val[i][j],edge[i][j]={n+i,j,val[i][j]};
        sort(edge[i]+1,edge[i]+1+n);
    }
    //solve2();return 0;
    //solve(0,1);solve3(1,2);return 0;
    for(int i=1;i<(1<<kk);i++){
        dp[i]=dp[i^lowbit(i)]+cost[lg[lowbit(i)]];
        ll w=solve(i^lowbit(i),lg[lowbit(i)]);
        ans=min(ans,w+dp[i]);
        //cout<<i<<": "<<w<<','<<dp[i]<<endl;
    }
    //cout<<solve3(_2[kk]-2,1)<<endl;
    cout<<ans;
    return 0;
}
