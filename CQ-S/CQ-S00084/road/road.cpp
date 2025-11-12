//Luogu: 1116515 Could you subscribe me?
#include <bits/stdc++.h>
using namespace std;
/*
美梦里学会感慨，你亦放肆你的爱。
用力转载，越过比赛，为我掩盖——都因为爱。
*/
struct edge{int u,v,w;} a[1100005];
int idx[1100005],flaggg[1100005];
int n,m,k,d[1005],ct[15],c[15][1005],e[15][1015],boss[1015];
int cmp(int p,int q){return a[p].w==a[q].w?p<q:a[p].w<a[q].w;}
int findrt(int x){return x==boss[x]?x:(boss[x]=findrt(boss[x]));}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w),idx[i]=i;
    sort(idx+1,idx+m+1,cmp);
    int cnt=0,ecnt=m;
    for(int i=1;i<=n;i++) boss[i]=i;
    for(int i=1;i<=m;i++){
        int u=findrt(a[idx[i]].u),v=findrt(a[idx[i]].v);
        if(u!=v) boss[u]=v,e[0][++cnt]=idx[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+k;j++) boss[j]=j;
        for(int j=1;j<n;j++) idx[j]=e[0][j];
        scanf("%d",&d[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&c[i][j]);
            a[++ecnt].u=j,a[ecnt].v=n+i,a[ecnt].w=c[i][j],idx[j+n-1]=ecnt;
        }
        sort(idx+1,idx+(n<<1),cmp);
        for(int j=1;j<(n<<1);j++){
            int u=findrt(a[idx[j]].u),v=findrt(a[idx[j]].v);
            if(u!=v){
                boss[u]=v;
                if(idx[j]>m) e[i][++ct[i]]=idx[j];
                else flaggg[idx[j]]|=1<<(i-1);
            }
        }
    }
    long long ans=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<(1<<k);i++){
        cnt=0;
        long long res=0;
        for(int j=1;j<=n+k;j++) boss[j]=j;
        for(int j=1;j<=k;j++){
            if(!((i>>(j-1))&1)) continue;
            res+=d[j];
            for(int p=1;p<=ct[j];p++) idx[++cnt]=e[j][p];
        }
        for(int p=1;p<n;p++)
            if((flaggg[e[0][p]]&i)==i) idx[++cnt]=e[0][p];
        sort(idx+1,idx+cnt+1,cmp);
        for(int j=1;j<=cnt;j++){
            int u=findrt(a[idx[j]].u),v=findrt(a[idx[j]].v);
            if(u!=v) boss[u]=v,res+=a[idx[j]].w;
        }
        ans=min(ans,res);
    }
    printf("%lld",ans);
    return 0;
}