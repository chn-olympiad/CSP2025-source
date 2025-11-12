#include<bits/stdc++.h>
#define getchar getchar_unlocked
template<class T> void read_unsigned(T &x){
    x=0; char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar());
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
}
template<class T,class ...Args> void read_unsigned(T &x,Args &...args){
    read_unsigned(x),read_unsigned(args...);
}
const int N=1e4+15,M=1e6+5;
int n,m,k,len,c[N],a[11][N];
struct kdge{ int u,v,w; }E[M],G[N*11];
int val[N*11],lv;
struct Disjoint_Set_Union{
    int rt[N];
    void init(){ std::iota(rt+1,rt+N,1); }
    int get_rt(int u){ return u==rt[u]?u:rt[u]=get_rt(rt[u]); }
}dsu;
long long Kruskal1(){
    std::sort(E+1,E+m+1,[](const kdge &a,const kdge &b){ return a.w<b.w; });
    int tot=0;
    long long sum=0;
    dsu.init();
    for(int i=1;tot<n-1;i++){
        auto [u,v,w]=E[i];
        int ru=dsu.get_rt(u),rv=dsu.get_rt(v);
        if(ru!=rv) tot++,G[++len]=E[i],dsu.rt[rv]=ru,sum+=w;
    }
    return sum;
}
std::basic_string<int> st[N*11];
long long Kruskal2(int pcnt){
    for(int i=1;i<=lv;i++) st[i].clear();
    for(int i=1;i<=len;i++) st[G[i].w].push_back(i);
    int tot=0;
    long long sum=0;
    dsu.init();
    for(int w=1;w<=lv;w++) for(auto i:st[w]){
        auto [u,v,w]=G[i];
        int ru=dsu.get_rt(u),rv=dsu.get_rt(v);
        if(ru!=rv){
            tot++,sum+=val[w],dsu.rt[rv]=ru;
            if(tot==n+pcnt-1) return sum;
        }
    }
    return -1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read_unsigned(n,m,k);
    for(int i=1;i<=m;i++) read_unsigned(E[i].u,E[i].v,E[i].w);
    for(int i=1;i<=k;i++){
        read_unsigned(c[i]);
        for(int j=1;j<=n;j++) read_unsigned(a[i][j]);
    }
    long long ans=Kruskal1();
    for(int i=1;i<n;i++) val[++lv]=G[i].w;
    for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) val[++lv]=a[i][j];
    std::sort(val+1,val+lv+1),lv=std::unique(val+1,val+lv+1)-(val+1);
    for(int i=1;i<n;i++) G[i].w=std::lower_bound(val+1,val+lv+1,G[i].w)-val;
    for(int i=1;i<=k;i++) for(int j=1;j<=n;j++)
        a[i][j]=std::lower_bound(val+1,val+lv+1,a[i][j])-val;
    for(int msk=0;msk<(1<<k);msk++){
        len=n-1;
        long long sum=0;
        for(int i=1;i<=k;i++) if(msk>>(i-1)&1){
            sum+=c[i];
            for(int j=1;j<=n;j++) G[++len]={n+i,j,a[i][j]};
        }
        ans=std::min(ans,Kruskal2(__builtin_popcount(msk))+sum);
    }
    std::cout<<ans;
    return 0;
}

