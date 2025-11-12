#include<bits/stdc++.h>
using namespace std;
const int N=1e4,M=1e6;
int n,m,k,c[15];
pair<int,int> a[15][N+5];
int fa[N+15];
inline int find(int x){return fa[x]==x? x:fa[x]=find(fa[x]);}
inline int merge(int u,int v){
    u=find(u),v=find(v);
    if(u==v) return 0;
    fa[u]=v; return 1;
}
struct node{
    int x,y,w;
    bool operator < (const node &rhs) const {
        return w<rhs.w;
    }
};
int cnt,at[15],rp[15];
long long tot,ans;
node rec[N+5],q[M+5];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k; int u,v,wp;
    for(int i=1;i<=m;i++) cin>>u>>v>>wp,q[i]={u,v,wp};
    sort(q+1,q+m+1);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j].first,a[i][j].second=j;
        sort(a[i]+1,a[i]+n+1);
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        if(merge(q[i].x,q[i].y)) tot+=q[i].w,rec[++cnt]=q[i];
    }
    ans=tot;
    for(int S=1;S<(1<<k);S++){
        tot=0; int lst=0;
        for(int i=1;i<=n+k;i++) fa[i]=i;
        for(int j=1;j<=k;j++){
            if((S>>(j-1))&1) tot+=c[j],at[j]=1,rp[lst]=j,lst=j;
            else at[j]=n+1;
        }
        rp[lst]=k+1,at[0]=1; node now;
        while(1){
            now={0,0,(int)1e9+1};
            if(at[0]<=cnt) now=rec[at[0]];
            for(int j=rp[0];j<=k;j=rp[j]){
                if(at[j]>n) continue;
                if(now.w>a[j][at[j]].first) now={n+j,a[j][at[j]].second,a[j][at[j]].first};
            }
            if(now.x==0) break;
            if(merge(now.x,now.y)) tot+=now.w;
            if(now.x<=n) at[0]++;
            else at[now.x-n]++;
        }
        ans=min(ans,tot);
    }
    cout<<ans<<"\n";
    return 0;
}