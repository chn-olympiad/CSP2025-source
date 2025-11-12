#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e4+5;
constexpr int M=1e6+7;
int n,m,k;
struct edge{
    int u,v,w;
    bool operator <(const edge &x)const{return w<x.w;}
};edge res[M],work[M<<1];
int c[15][N];
int fa[N+50];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    // if(!k){
        for(int i=1;i<=m;i++) cin>>res[i].u>>res[i].v>>res[i].w;
        sort(res+1,res+1+m);
        int tot=0;
        for(int i=1;i<=n;i++) fa[i]=i;
        long long mstans=0;
        for(int i=1;i<=m;i++){
            int u=find(res[i].u),v=find(res[i].v);
            if(u==v) continue;
            fa[u]=v;mstans+=res[i].w;
            if(++tot==n-1) break;
        }
        if(!k){
            cout<<mstans;return 0;
        }
        // cout<<ans;return 0;
    // }else{
        // for(int i=1;i<=m;i++) cin>>res[i].u>>res[i].v>>res[i].w;
        for(int i=1;i<=k;i++){
            for(int j=0;j<=m;j++) cin>>c[i][j];
        }
        // for(int i=1;i<=k;i++){
        //     for(int j=0;j<=m;j++) cout<<c[i][j]<<" ";cout<<'\n';
        // }
        long long sumans=mstans;
        for(int dp=1;dp<=(1<<k)-1;dp++){
            // cout<<dp<<":"<<'\n';
            bool con=0;
            for(int i=1;i<=m;i++) work[i]=res[i];
            long long ans=0;
            int edgetot=m,pointtot=n;
            for(int i=0;i<k;i++) if(((dp>>i)&1)){
                if(c[i+1][0]>mstans){con=1;break;}
                ans+=c[i+1][0];pointtot++;
                for(int j=1;j<=n;j++){
                    ++edgetot;
                    work[edgetot].u=i+n+1;
                    work[edgetot].v=j;
                    work[edgetot].w=c[i+1][j];
                    // cout<<"warn"<<" "<<i+1<<" "<<j<<" "<<c[i+1][j]<<'\n';
                }
            }
            if(con) continue;
            sort(work+1,work+1+edgetot);
            for(int i=1;i<=pointtot;i++) fa[i]=i;
            int tmptot=0;
            for(int i=1;i<=edgetot;i++){
                int u=find(work[i].u),v=find(work[i].v);
                if(u==v) continue;
                // cout<<work[i].u<<" "<<work[i].v<<" "<<work[i].w<<'\n';
                fa[u]=v;tmptot++;
                ans+=work[i].w;
                if(tmptot==pointtot-1) break;
            }
            sumans=min(sumans,ans);
            // cout<<ans<<" "<<sumans<<'\n';
        }
        cout<<sumans<<'\n';
    // }
    return 0;
}