#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=12;
struct edge{int u,v,w;bool flg;};
int n,m,k,cnt,tot,fa[N],c[K];
edge mem[M],hlp[M],e[M],e1[K][N];
long long ans;
inline void file(){freopen("road.in","r",stdin),freopen("road.out","w",stdout);}
inline bool cmp(edge a,edge b){return a.w<b.w;}
inline void init(int x){cnt=x;for(int i(1);i<=x;++i) fa[i]=i;}
int find(int p){return(p!=fa[p])?fa[p]=find(fa[p]):p;}
inline long long solve(int x){
    long long res(0);
    tot=n-1,cnt=n;
    for(int i(0);i<k;++i) if(x&(1<<i)){
        res+=c[i],++cnt;
        memcpy(hlp,mem,sizeof(edge)*(tot+1));
        for(int p(1),q(1);p<=tot;++p){
            while(q<=n&&hlp[p].w>e1[i][q].w) mem[p+q-1]=e1[i][q],mem[p+q-1].u=cnt,++q;
            mem[p+q-1]=hlp[p];
        }
        tot+=n;
    }
    init(cnt);
    for(int i(1),u,v;i<=tot;++i){
        u=find(mem[i].u),v=find(mem[i].v);
        if(u==v) continue;
        fa[u]=v,--cnt,res+=mem[i].w;
        if(cnt==1) break;
    }
    for(int i(1),p(1);i<=tot;++i) if(!mem[i].flg) swap(mem[i],mem[p]),++p;
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> n >> m >> k;
    for(int i(1);i<=m;++i) cin >> e[i].u >> e[i].v >> e[i].w,e[i].flg=0;
    for(int i(0);i<k;++i){
        cin >> c[i];
        for(int j(1),a;j<=n;++j) cin >> a,e1[i][j]={i,j,a,1};
        sort(e1[i]+1,e1[i]+n+1,cmp);
    }
    sort(e+1,e+m+1,cmp),init(n);
    for(int i(1),u,v;i<=m;++i){
        u=find(e[i].u),v=find(e[i].v);
        if(u==v) continue;
        fa[u]=v,--cnt,mem[++tot]=e[i],ans+=e[i].w;
        if(cnt==1) break;
    }
    for(int i(1);i<(1<<k);++i) ans=min(ans,solve(i));
    cout << ans;
    return 0;
}
/*
电脑卡成啥了，我真服了。
挑战猜测终端命令位置。
*/