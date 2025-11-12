#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
    int u,v;
    long long w;
};
Node X[15][100005];
Node edge[1000005];
Node S[1000005];
long long a[15][100005],c[15];
bool B[15];
const long long maxn=1e15+5;
long long ans=maxn,cnt;
bool cmp(Node x,Node y){
    if(x.w!=y.w) return x.w<y.w;
    if(x.v!=y.v) return x.v<y.v;
    return x.u<y.u;
}
int f[2000005];
int tmp;
void mv(Node &x,Node y){
    x.u=y.u;
    x.v=y.v;
    x.w=y.w;
}
int fa(int x){
    if(f[x]!=f[f[x]]) f[x]=fa(f[x]);
    return f[x];
}
int pe,ps,aa,bb;
long long solve(int t){
    cnt=1;
    for(int i=1;i<=k;i++) B[i]=((t/cnt)%2),cnt*=2;
    cnt=0;t=0;
    for(int i=1;i<=k;i++){
        if(!B[i]) continue;
        cnt+=c[i];
        for(int j=1;j<=n;j++) mv(S[t*n+j],X[i][j]);
        t++;
    }
    if(t!=0)
        sort(S+1,S+t*n,cmp);
    S[t*n+1].w=maxn;
    edge[m+1].w=maxn;
    if(cnt>ans) return maxn;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int j=1;j<=k;j++) f[j+m]=j+m;
    tmp=1;
    pe=1,ps=1;
    while(tmp<n+t){
        if(cmp(edge[pe],S[ps])){
            aa=fa(edge[pe].u),bb=fa(edge[pe].v);
            pe++;
            if(aa==bb) continue;
            f[bb]=aa;
            cnt+=edge[pe-1].w;
            tmp++;
        }
        else{
            aa=fa(S[ps].u),bb=fa(S[ps].v);
            ps++;
            if(aa==bb) continue;
            f[bb]=aa;
            cnt+=S[ps-1].w;
            tmp++;
        }
        if(cnt>=ans) return maxn;
    }
    return cnt;
}


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    sort(edge+1,edge+m+1,cmp);
    int t=1;
    for(int i=1;i<=k;i++){
        t*=2;
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++) X[i][j].u=i+m,X[i][j].v=j;
        for(int j=1;j<=n;j++) scanf("%lld",&X[i][j].w);
    }
    for(int i=0;i<t;i++){
        ans=min(ans,solve(i));
    }
    printf("%lld\n",ans);
    return 0;
}
