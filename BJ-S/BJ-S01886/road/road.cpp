#include<bits/stdc++.h>
using namespace std;
const int V = 1e4+10;
const int E = 1e6+10;
int N,M,k;
int f[V],c[16];
struct Edge{
    int u,v,w,ne;
}e[E];
int tq,pr[V];
inline void add(int u,int v,int w){
    tq++;
    e[tq].u = u;
    e[tq].v = v;
    e[tq].w = w;
    e[tq].ne = pr[u];
    pr[u] = tq;
}
inline bool cmp(Edge x,Edge y){
    return x.w < y.w;
}
inline int gf(int x){
    if(x == f[x]) return x;
    return f[x] = gf(f[x]);
}
inline void init(int n){
    for(int i = 1;i <= n;i++) f[i] = i;
}
inline long long kruscal(int n,int m){
    init(n);
    sort(e+1,e+m+1,cmp);
    long long cnt = n,ans = 0;
    for(int i = 1;i <= m;i++){
        int u = gf(e[i].u),v = gf(e[i].v);
        if(u == v) continue;
        f[u] = v;
        ans += e[i].w;
        e[i].w = 0;
        cnt--;
        if(cnt <= 1) break;
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&N,&M,&k);
    int n = N,m = M;
    for(int i = 1;i <= m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
    }
    //printf("%lld\n",kruscal(n,m));
    long long sumc = 0;
    for(int i = n+1;i <= n+k;i++){
        scanf("%d",&c[i]);
        sumc += c[i];
        for(int j = 1;j <= n;j++){
            int w;
            scanf("%d",&w);
            add(i,j,w);
            m++;
        }
    }
/*
    long long val = kruscal(n+k,m) + sumc,mm = 0;
    printf("%lld\n",val-sumc);
    for(int i = 1;i <= k;i++){
        long long cnt = 0;
        for(int j = pr[n+i];j;j = e[j].ne){
            cnt += e[j].w;
            e[j].w = 0x3f3f3f3f;
        }
        long long cm_ = kruscal(n,m);
        printf("%lld %lld\n",cm_,cnt);
        if(cnt + c[i] > cm_){
            mm += cnt + c[i] - cm_;
        }
        for(int j = pr[n+i];j;j = e[j].ne){
            e[j].w = 0;
        }
    }
    printf("%lld",val-mm);*/
    printf("%lld",kruscal(n+k,m) + sumc);
    return 0;
}
