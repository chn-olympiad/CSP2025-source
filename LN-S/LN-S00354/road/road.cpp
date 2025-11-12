#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[20],a[20][10010],ans=1e18,f[10020];
bool b[20];
struct Edge_{
    int u,v,w;
}ed[110010];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(Edge_ x,Edge_ y){
    return x.w<y.w;
}
void DFS_(int x){
    if(x>k){
        for(int i=1;i<=n+k;i++)f[i]=i;
        int m_=m,sum=0,cnt=0,anss=0;
        for(int i=1;i<=k;i++)if(b[i]){
            cnt++;
            anss+=c[i];
            for(int j=1;j<=n;j++){
                ed[++m_].u=j;
                ed[m_].v=i+n;
                ed[m_].w=a[i][j];
                ed[++m_].u=i+n;
                ed[m_].v=j;
                ed[m_].w=a[i][j];
            }
        }
        sort(ed+1,ed+m_+1,cmp);
        for(int i=1;i<=m_;i++)if(find(ed[i].u)!=find(ed[i].v)){
            f[find(ed[i].u)]=find(ed[i].v);
            sum++;
            anss+=ed[i].w;
            if(sum==n+cnt-1)break;
        }
        if(sum==n+cnt-1)ans=min(ans,anss);
        return;
    }
    DFS_(x+1);
    b[x]=1;
    DFS_(x+1);
    b[x]=0;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&ed[i].u,&ed[i].v,&ed[i].w);
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
    }
    DFS_(1);
    printf("%lld",ans);
    return 0;
}
