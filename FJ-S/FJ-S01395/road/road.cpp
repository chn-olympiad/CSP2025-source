#include<bits/stdc++.h>
constexpr int rSiz=1<<21;
char rBuf[rSiz],*p1=rBuf,*p2=rBuf;
#define gc() (p1==p2&&(p2=(p1=rBuf)+fread(rBuf,1,rSiz,stdin),p1==p2)?EOF:*p1++)
template<class T>void rd(T&x){
    char ch=gc();
    for(;ch<'0'||ch>'9';ch=gc());
    for(x=0;ch>='0'&&ch<='9';ch=gc())
        x=(x<<1)+(x<<3)+(ch^48);
}
constexpr int _=2e4+5,__=2e6+5;
int n,m,k,cnt,d[_],tot;
struct edge{int u,v,w;}e[__];
int c[12],p[12];
std::pair<int,int>a[12][_];
int fa[_];
int Fnd(int x){return x==fa[x]?x:fa[x]=Fnd(fa[x]);}
std::priority_queue<std::pair<int,int> >q;
long long ans;
#define fio(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
int main(){
    fio("road");
    rd(n),rd(m),rd(k);
    for(int i=1;i<=m;++i)rd(e[i].u),rd(e[i].v),rd(e[i].w);
    std::sort(e+1,e+m+1,[](edge A,edge B){return A.w<B.w;});
    for(int i=1;i<=k;++i){
        rd(c[i]);for(int u=1,x;u<=n;++u)rd(x),a[i][u]={x,u};
        std::sort(a[i]+1,a[i]+n+1);
    }
    for(int i=1;i<=n;++i)fa[i]=i;
    cnt=0;
    for(int i=1;i<=m;++i){
        int u=Fnd(e[i].u),v=Fnd(e[i].v);
        if(u^v)fa[u]=v,ans+=e[i].w,d[++tot]=i,++cnt;
        if(cnt==n-1)break;
    }
    for(int S=1;S<(1<<k);++S){
        cnt=0;long long val=0;
        for(;!q.empty();q.pop());
        for(int i=1;i<=n;++i)fa[i]=i;
        for(int i=1;i<=k;++i)if(S>>(i-1)&1){
            q.push({-a[i][1].first,i});--cnt;
            fa[n+i]=n+i,p[i]=1;val+=c[i];
        }
        for(int i=1;i<=tot;++i){
            int j=d[i],u,v;
            for(;!q.empty()&&-q.top().first<=e[j].w;){
                int o=q.top().second;q.pop();
                u=Fnd(a[o][p[o]].second),v=Fnd(n+o);
                if(u^v)fa[u]=v,val+=a[o][p[o]].first,++cnt;
                ++p[o];if(p[o]<=n)q.push({-a[o][p[o]].first,o});
            }
            u=Fnd(e[j].u),v=Fnd(e[j].v);
            if(u^v)fa[u]=v,val+=e[j].w,++cnt;
            if(cnt==n-1)break;
        }
        ans=std::min(ans,val);
    }
    printf("%lld\n",ans);
}