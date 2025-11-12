#include <bits/stdc++.h>
typedef long long ll;
const int N=1e4+15,M=1e6+15;
inline int rd(){
    int r=0;char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) r=r*10-'0'+c,c=getchar();
    return r;
}
ll ans;
int n,m,k,cnt;
int boss[N];
int find(int x){
    return boss[x] = boss[x] == x ? x : find(boss[x]);
}

struct edge{
    int u,v,w;
}e[M],tree[M];
int c[11],a[11][N];

inline bool cmp(const edge &x,const edge &y){return x.w<y.w;}

void get_tree(){
    for(int i=1;i<=n;++i) boss[i]=i;
    std::sort(e+1,e+1+m,cmp);
    int tt=0;
    for(int i=1;i<=m;++i){
        if(find(e[i].u)!=find(e[i].v)){
            boss[find(e[i].u)]=find(e[i].v);
            tree[++tt]=e[i];
            ans+=e[i].w;
        }
        if(tt==n-1) break;
    }
    cnt=n-1;
}

ll sol(int S){
    ll res=0;
    for(int i=1;i<=k;++i) if((S>>(i-1))&1) res+=c[i];
    //cerr<<"S: "<<S<<" res: "<<res<<endl;
    for(int i=1;i<=n+k;++i) boss[i]=i;
    for(int i=1;i<=cnt;++i) {
        int u=tree[i].u,v=tree[i].v,w=tree[i].w;
        if(u>n && ((S>>(u-n-1))&1)==0) continue;
        if(find(u)!=find(v)){
            boss[find(u)]=find(v);
            res+=w;
        }
    }
    return res;
}

int main(){
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    n=rd(),m=rd(),k=rd();
    for(int i=1;i<=m;++i) e[i].u=rd(),e[i].v=rd(),e[i].w=rd();
    for(int i=1;i<=k;++i){
        c[i]=rd();
        for(int j=1;j<=n;++j) a[i][j]=rd();
    }
    get_tree();
    //cerr<<"*ans: "<<ans<<endl;
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j){
            tree[++cnt]={n+i,j,a[i][j]};
        }
    }
    std::sort(tree+1,tree+1+cnt,cmp);
    for(int S=1;S<(1<<k);++S){
        ans=std::min(sol(S),ans);
    }
    printf("%lld\n",ans);
    return 0;
}