#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=3e6+5;
int n,m,k,d[10][maxn],f[maxn],p[maxn],c[maxn];
long long ans=1e18;

struct node{
    int u,v,w;
}t[maxn],t2[maxn];

void _init(int cur){
    for(int i=1;i<=cur;i++) f[i]=i;
}
int _find(int i){
    return f[i]==i?f[i]:f[i]=_find(f[i]);
}
void _merge(int i,int j){
    int a=_find(i),b=_find(j);
    if(a!=b) f[a]=b;
    return;
}
bool _query(int i,int j){
    return _find(i)==_find(j);
}
bool cmp(node x,node y){
    return x.w<y.w;
}

long long calc(){
    for(int i=1;i<=m;i++) t2[i].u=t[i].u,t2[i].v=t[i].v,t2[i].w=t[i].w;
    int cur=m,curd=n;
    long long res=0;
    for(int i=1;i<=k;i++){
        if(p[i]==1){
            for(int j=1;j<=n;j++){
                t2[++cur].u=i+n;
                t2[cur].v=j;
                t2[cur].w=d[i][j];
            }
            res+=c[i];curd++;
        }
    }
    sort(t2+1,t2+1+cur,cmp);
    _init(cur);
    int cnt=0;
    for(int i=1;i<=cur;i++){
        if(!_query(t2[i].u,t2[i].v)){
            _merge(t2[i].u,t2[i].v);
            res+=t2[i].w;cnt++;
        }
        if(cnt==curd-1) break;
    }
    return res;
}

void dfs(int s){
    if(s==k+1){
        ans=min(ans,calc());
        return;
    }
    p[s]=1;dfs(s+1);
    p[s]=0;dfs(s+1);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);ans=1e18;
    for(int i=1;i<=m;i++) scanf("%d%d%d",&t[i].u,&t[i].v,&t[i].w);
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++) scanf("%d",&d[i][j]);
    }
    bool flag=1;
    for(int i=1;i<=k;i++){
        if(c[i]>=1) flag=0;
    }
    if(flag==1){
        int cur=m,curd=n+k;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                t[++cur].u=i+n,t[cur].v=j,t[cur].w=d[i][j];
            }
        }
        sort(t+1,t+1+cur,cmp);
        _init(curd);
        int cnt=0;
        long long res=0;
        for(int i=1;i<=cur;i++){
            if(!_query(t[i].u,t[i].v)){
                _merge(t[i].u,t[i].v);
                res+=t[i].w;cnt++;
            }
            if(cnt==curd-1) break;
        }
        printf("%lld\n",res);
    }
    else{
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
