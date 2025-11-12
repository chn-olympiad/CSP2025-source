#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c;
int l[1000005],r[1000005],x[1000005],fa[100005],cnt;
int gai[105][10005];
struct m{
    int u,v,w;
}edge[3000005];
bool cmp(m a,m b){
    return a.w<b.w;
}
int getfa(int x){
    if(x==fa[x])return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}
int p[100005],ans,rans;
void dfs(int now){
    if(now==c+1){
        ans=0;
        int ge=0;
        for(int i=1;i<=c;i++){
            if(p[i]==1){
                ans+=gai[i][0];
                ge++;
            }
        }
        for(int i=1;i<=c+a;i++){
            fa[i]=i;
        }
        int sum=0;
        for(int i=1;i<=cnt;i++){
            if(edge[i].u-a>0&&p[edge[i].u-a]==0)continue;
            if(edge[i].v-a>0&&p[edge[i].v-a]==0)continue;
            int xx=getfa(edge[i].u);
            int yy=getfa(edge[i].v);
            if(xx==yy)continue;
            sum++;
            fa[xx]=yy;
            ans+=edge[i].w;
            if(sum==a+ge-1)break;
        }
        rans=min(rans,ans);
        return ;
    }
    p[now]=1;
    dfs(now+1);
    p[now]=0;
    dfs(now+1);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld %lld",&a,&b,&c);
    for(int i=1;i<=b;i++){
        scanf("%lld %lld %lld",&l[i],&r[i],&x[i]);

    }
    for(int i=1;i<=b;i++){
        edge[++cnt]={l[i],r[i],x[i]};
        edge[++cnt]={r[i],l[i],x[i]};
    }
    for(int i=1;i<=c;i++){
        for(int j=0;j<=a;j++){
            scanf("%lld",&gai[i][j]);
        }
        for(int j=1;j<=a;j++){
            edge[++cnt]={i+a,j,gai[i][j]};
            edge[++cnt]={j,i+a,gai[i][j]};
        }
    }
    sort(edge+1,edge+cnt+1,cmp);
    rans=1e15;
    dfs(1);
    printf("%lld",rans);
    return 0;
}
