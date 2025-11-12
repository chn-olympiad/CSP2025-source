#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    int x,y,w;
};
bool cmp(node x,node y){
    return x.w<y.w;
}
node t[10007],ng[17][10007];
node e[1000007],p[1000007];
int c[17],vis[17],f[10017],a[17][10007],k,n,cur[17],pre[10007],nxt[10007];
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
long long ans=1e18;
void dfs(int u){
    if(u>k){
        int tot=0;
        long long sum=0;
        int cb=n;
        for(int i=1;i<=k;i++) cur[i]=1,pre[i]=i-1,nxt[i]=i+1;
        nxt[0]=1;
        pre[k+1]=k;
        bool flag=false;
        int cc=0;
        vis[0]=1;
        while(true){
            node now;
            now.w=1e9+7;
            // printf("cc:%d %d\n",cc,nxt[0]);
            // for(int i=1;i<=k;i++) printf("%d %d %d\n",vis[i],nxt[i],pre[i]);
            // cc++;
            int idx=0;
            for(int i=nxt[0];i<=k;i=nxt[i]){
                if(!vis[i] || cur[i]>n){
                    if(nxt[pre[i]]==i){
                        nxt[pre[i]]=nxt[i];
                        pre[nxt[i]]=pre[i];
                    }
                    continue;
                }
                if(ng[i][cur[i]].w<now.w){
                    now=ng[i][cur[i]];
                    idx=i;
                }
            }
            if(now.w==1e9+7) break;
            e[++tot]=now;
            cur[idx]++;
            // printf("bian:%d %d %d\n",now.x,now.y,now.w);
        }
        for(int i=1;i<=k;i++){
            if(vis[i]){
                cb++;
                sum+=c[i];
                // if(sum>ans) return;
            }
        }
        // printf("ew:\n");
        // for(int i=1;i<=k;i++) printf("%d ",vis[i]);
        // printf("\n");
        // for(int i=1;i<=tot;i++) printf("%d\n",e[i].w);
        int ct=0,l=1,r=1;
        while(l<=tot && r<=(n-1)){
            if(e[l].w<t[r].w){
                p[++ct]=e[l];
                l++;
            }else{
                p[++ct]=t[r];
                r++;
            }
        }
        while(l<=tot) p[++ct]=e[l],l++;
        while(r<=(n-1)) p[++ct]=t[r],r++;
        for(int i=1;i<=n+k;i++) f[i]=i;
        // sort(e+1,e+1+tot,cmp);
        int ccb=0;
        for(int i=1;i<=ct;i++){
            int x=find(p[i].x),y=find(p[i].y);
            if(x==y) continue;
            f[x]=y;
            ccb++;
            sum+=p[i].w;
            if(sum>ans) return;
            if(ccb==cb-1) break;
        }
        ans=min(ans,sum);
        return;
    }
    vis[u]=1;
    dfs(u+1);
    vis[u]=0;
    dfs(u+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        e[i]=(node){x,y,w};
    }
    sort(e+1,e+1+m,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++) f[i]=i;
    ans=0;
    for(int i=1;i<=m;i++){
        int x=find(e[i].x),y=find(e[i].y);
        if(x==y) continue;
        f[x]=y;
        t[++cnt]=e[i];
        ans+=e[i].w;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            ng[i][j]=(node){n+i,j,a[i][j]};
        }
        sort(ng[i]+1,ng[i]+1+n,cmp);
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}