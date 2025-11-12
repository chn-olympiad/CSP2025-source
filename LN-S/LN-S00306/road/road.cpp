#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,tot,ans,minn,fa[10005],li[2005],bian[15][10005],city[15],a[15];
struct Edge{
    int u,v,w;
}e[2000005];
int finda(int x){
    if(fa[x]==x) return x;
    return finda(fa[x]);
}
bool cmp(Edge p,Edge q){
    return p.w<q.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    if(k==0){
        sort(e+1,e+m+1,cmp);
        for(int i=1;i<=m;i++){
            int x=e[i].u,y=e[i].v;
            int fx=finda(x),fy=finda(y);
            if(fx!=fy){
                ans+=e[i].w;
                fa[y]=x;
                cnt++;
            }
            if(cnt==n-1){
                printf("%lld\n",ans);
                return 0;
            }
        }
    }
    minn=0x7fffffff;
    for(int i=1;i<=k;i++){
        scanf("%lld",&city[i+n]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&bian[i+n][j]);
        }
    }
    int cnt1=0;
    for(int i=0;i<=((1<<k)-1);i++) li[++cnt1]=i;
    for(int kk=1;kk<=cnt1;kk++){
        ans=0,cnt=0;
        tot=m;
        int js=0,cnt2=0;
        int x=li[kk];
        while(x){
            js++;
            if(x&1) a[++cnt2]=js+n;
            x>>=1;
        }
        for(int i=1;i<=cnt2;i++){
            ans+=city[a[i]];
            for(int j=1;j<=n;j++){
                e[++tot].u=a[i],e[tot].v=j,e[tot].w=bian[a[i]][j];
            }
        }
        for(int i=1;i<=n+cnt2;i++) fa[i]=i;
        sort(e+1,e+tot+1,cmp);
        for(int i=1;i<=tot;i++){
            int x=e[i].u,y=e[i].v;
            int fx=finda(x),fy=finda(y);
            if(fx!=fy){
                ans+=e[i].w;
                fa[y]=x;
                cnt++;
            }
            if(cnt==n+cnt2-1){
                minn=min(ans,minn);
                break;
            }
        }
    }
    printf("%lld",minn+1);
    return 0;
}
/*
7 10 0
1 2 1
1 3 1
2 4 11
2 5 1
1 7 10
3 6 2
3 7 4
1 2 14
1 5 21
2 5 13
*/


