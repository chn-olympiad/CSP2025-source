#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+17,M=2e6+7;
int n,m,k;
ll c[11];
ll cc[N][11];
int fa[N];

int FIND(int u){
    if(fa[u]==u) return fa[u];
    return fa[u]=FIND(fa[u]);
}

void merge(int u,int v){
    u=FIND(u);v=FIND(v);
    if(u==v) return;
    fa[u]=v;
}

void init(){
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
}

struct node{
    int u,v;
    ll w;
}b[M],temp[M];

bool cmp(node a,node b){
    return a.w<b.w;
}

ll ans;
void solve1(){
    sort(b+1,b+1+m,cmp);
    init();
    ans=0;
    for(int i=1;i<=m;i++){
        if(FIND(b[i].u)!=FIND(b[i].v)){
            merge(b[i].u,b[i].v);
            ans+=b[i].w;
        }
    }
    cout<<ans;
}

ll solve2(int f){
    init();
    int tmp=m,cnt=n;
    ll sum=0;
    for(int i=1;i<=k;i++){
        if(f&(1<<(i-1))){
            sum+=c[i];
            cnt++;
            for(int j=1;j<=n;j++){
                b[++tmp]={n+i,j,cc[j][i]};
            }
        }
    }
    sort(b+1,b+1+tmp,cmp);
    for(int i=1;i<=tmp;i++){
        if(FIND(b[i].u)!=FIND(b[i].v)){
            merge(b[i].u,b[i].v);
            sum+=b[i].w;
            cnt--;
        }
        if(cnt==1) break;
    }
    for(int i=1;i<=m;i++){
        b[i]=temp[i];
    }
    return sum;
}

int uf[11],u;

void dfs(int i,int sum){
    if(i>u){
        ans=min(solve2(sum),ans);
        return;
    }
    dfs(i+1,sum+uf[i]);
    dfs(i+1,sum);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&b[i].u,&b[i].v,&b[i].w);
        temp[i]=b[i];
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",c+i);

        for(int j=1;j<=n;j++){
            scanf("%lld",&cc[j][i]);
        }
    }
    if(k==0) solve1();
    else{
        ans=solve2(0);
        for(int i=1;i<(i<<k);i<<=1){
            if(solve2(i)<ans) uf[++u]=i;
        }
        dfs(1,0);
        cout<<ans;
    }
    return 0;
}
