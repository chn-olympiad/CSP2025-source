#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+2,M=1e4+32;
struct edge{int u,v,w;}e[N],d[N<<1];
int c[12],a[12][M],fa[M],tot;
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    tot=m;
    bool flag=1;
    for(int i=1;i<=k;i++){
        bool f=1;
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0) f=1;
        }
        if(c[i]!=0||f==0) flag=0;
    }
    if(flag){
        for(int i=1;i<=m;i++) d[i]=e[i];
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                d[++tot]={n+i,j,a[i][j]};
            }
        }
        for(int i=1;i<=n+k;i++) fa[i]=i;
        sort(d+1,d+1+tot,cmp);
        ll ans=0,cnt=0;
        for(int i=1;i<=tot;i++){
            int u=find(d[i].u),v=find(d[i].v),w=d[i].w;
            if(u==v) continue;
            fa[u]=v,cnt++,ans+=w;
            if(cnt==n+k-1) break;
        }
        cout<<ans;
        return 0;
    }
    else{
        ll ans=1e18;
        for(int s=0;s<(1<<k);s++){
            int cnt=0;
            ll res=0,sum=0;
            for(int i=1;i<=m;i++) d[i]=e[i];
            tot=m;
            for(int i=1;i<=k;i++){
                if((s>>(i-1))==0) continue;
                cnt++,res+=c[i];
                for(int j=1;j<=n;j++){
                    d[++tot]={n+cnt,j,a[i][j]};
                }
            }
            for(int i=1;i<=n+cnt;i++) fa[i]=i;
            sort(d+1,d+1+tot,cmp);
            for(int i=1;i<=tot;i++){
                int u=find(d[i].u),v=find(d[i].v),w=d[i].w;
                if(u==v) continue;
                fa[u]=v,sum++,res+=w;
                if(sum==n+cnt-1) break;
            }
            ans=min(ans,res);
        }
        cout<<ans;
    }
    return 0;
}