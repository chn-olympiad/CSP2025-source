#include<bits/stdc++.h>
#define int long long
using namespace std;

//long long file limit memory

const int N=2e4+10,M=2e6+10;
int n,m,k,fa[N],a[20][N],c[20];
int can[20],cnt[20],t[20];
struct node{
    int u,v,w;
    bool operator < (const node &x)const{
        return w<x.w;
    }
}e[M],e2[M];
int getfa(int x){
    return (x==fa[x])?x:fa[x]=getfa(fa[x]);
}
void do1(){
    for(int i=1;i<=k;i++){
        int p=1;
        for(int j=1;j<=n;j++){
            if(a[i][j]==0) p=j;
        }
        for(int j=1;j<=n;j++){
            if(j==p) continue;
            e[++m]=(node){p,j,a[i][j]};
        }
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    int ans1=0;
    for(int i=1,bs=0;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fu=getfa(u),fv=getfa(v);
        if(fu!=fv){
            fa[fu]=fv;
            ans1+=w,bs++;
            //cout<<u<<" "<<v<<" "<<w<<"\n";
        }
        if(bs==n-1) break;
    }
    printf("%lld",ans1);
    exit(0);
}
void do2(){
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    int ans1=0;
    for(int i=1,bs=0;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fu=getfa(u),fv=getfa(v);
        if(fu!=fv){
            fa[fu]=fv;
            ans1+=w,bs++;
            //cout<<u<<" "<<v<<" "<<w<<"\n";
        }
        if(bs==n-1) break;
    }
    printf("%lld",ans1);
    exit(0);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    }
    int sum=0;
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        sum+=c[i];
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    if(sum==0) do1();
    if(k==0) do2();

    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    int ans1=0,ans=0;
    for(int i=1,bs=0;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fu=getfa(u),fv=getfa(v);
        if(fu!=fv){
            fa[fu]=fv;
            ans1+=w,bs++;
        }
        if(bs==n-1) break;
    }
    ans=ans1;
    for(int p=1;p<=k;p++){
        int ret=c[p];
        for(int i=1;i<=n+1;i++) fa[i]=i;
        for(int i=1;i<=m;i++) e2[i]=e[i];
        for(int i=1;i<=n;i++) e2[m+i]=(node){n+1,i,a[p][i]};
        sort(e2+1,e2+m+n+1);
        for(int i=1,bs=0;i<=m+n;i++){
            int u=e2[i].u,v=e2[i].v,w=e2[i].w;
            int fu=getfa(u),fv=getfa(v);
            if(fu!=fv){
                fa[fu]=fv;
                ret+=w,bs++;
            }
            if(bs==n) break;
        }
        if(ret<ans1) can[p]=1;
        ans=min(ans,ret);
    }
    int ans2=0,num=0;
    for(int p=1;p<=k;p++){
        if(!can[p]) continue;
        num++,ans2+=c[p];
        for(int i=1;i<=n;i++){
            e[++m]=(node){n+p,i,a[p][i]};
        }
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n+num;i++) fa[i]=i;
    for(int i=1,bs=0;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fu=getfa(u),fv=getfa(v);
        if(fu!=fv){
            fa[fu]=fv;
            ans2+=w,bs++;
            if(u>n) cnt[u-n]++,t[u-n]=w;
            if(v>n) cnt[v-n]++,t[v-n]=w;
        }
        if(bs==n+num-1) break;
    }
    for(int i=1;i<=k;i++){
        if(!can[i]) continue;
        if(cnt[i]<=1) ans2-=(t[i]+c[i]);
    }
    ans=min(ans,ans2);
    printf("%lld",ans);
    return 0;
}
