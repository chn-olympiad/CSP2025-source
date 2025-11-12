#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
    int u,v,w;
    bool operator <(const st&b) const{
        return w<b.w;
    }
} e[1000005],nw[10005],cur[100005];
int c[15],a[15][10005],fa[10015],cnt;
ll ans;
int getfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+m+1);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    int tmp=1;
    for(int i=1;i<=m;i++){
        if(tmp==n) break;
        int fx=getfa(e[i].u),fy=getfa(e[i].v);
        if(fx!=fy) fa[fx]=fy,nw[++cnt]=e[i],ans+=e[i].w,tmp++;
    }
    for(int i=0;i<(1<<k);i++){
        ll res=0,tot=0,now=1;
        for(int j=1;j<=cnt;j++) cur[j]=nw[j];
        for(int j=0;j<k;j++)
            if((i>>j)&1){
                res+=c[j+1],tot++;
                for(int l=1;l<=n;l++) cur[++cnt].u=n+tot,cur[cnt].v=l,cur[cnt].w=a[j+1][l];
            }
        sort(cur+1,cur+cnt+1);
        for(int i=1;i<=n+tot;i++) fa[i]=i;
        for(int i=1;i<=cnt;i++){
            if(now==n+tot) break;
            int fx=getfa(cur[i].u),fy=getfa(cur[i].v);
            if(fx!=fy) fa[fx]=fy,res+=cur[i].w,now++;
        }
        ans=min(ans,res),cnt=n-1;
    }
    cout<<ans;
}