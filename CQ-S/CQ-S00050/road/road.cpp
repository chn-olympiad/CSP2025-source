#include<bits/stdc++.h>
using namespace std;
inline char gtchar(){
    static char buf[1000005],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000005,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=gtchar();
    int x=0;
    while(ch<'0'||ch>'9') ch=gtchar();
    while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gtchar();
    return x;
}
struct edge{
    int x,y,w;
}d[1<<10|5][10015],e[1000005],f[15][10005];
int n,m,k,cnt,val[15];
long long sum,ans,tot[1<<10|5];
namespace dsu{
    int fa[10015];
    inline void init(){
        iota(fa+1,fa+1+n+k,1);
    }
    inline int findfather(int v){
        return fa[v]==v?v:fa[v]=findfather(fa[v]);
    }
    inline bool merge(int x,int y){
        x=findfather(x),y=findfather(y);
        if(x==y) return 0;
        fa[x]=y;
        return 1;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].w=read();
    sort(e+1,e+1+m,[](edge&x,edge&y)->bool{return x.w<y.w;}),dsu::init();
    for(int i=1;i<=m;i++) if(dsu::merge(e[i].x,e[i].y)) d[0][++cnt]=e[i],ans+=e[i].w;
    for(int i=1;i<=k;i++){
        val[i]=read();
        for(int j=1;j<=n;j++) f[i][j].x=j,f[i][j].y=i+n,f[i][j].w=read();
        sort(f[i]+1,f[i]+1+n,[](edge&x,edge&y)->bool{return x.w<y.w;});
    }
    for(int i=1;i<(1<<k);i++){
        int w1=i^(i&-i),w2=__builtin_ctz(i)+1,p1=1,p2=1,t1=n+__builtin_popcount(i)-2,t2=n;
        sum=tot[i]=tot[w1]+val[w2],dsu::init(),cnt=0;
        while(p1<=t1&&p2<=t2){
            if(d[w1][p1].w<f[w2][p2].w){
                if(dsu::merge(d[w1][p1].x,d[w1][p1].y)) d[i][++cnt]=d[w1][p1],sum+=d[w1][p1].w;
                p1++;
            }
            else{
                if(dsu::merge(f[w2][p2].x,f[w2][p2].y)) d[i][++cnt]=f[w2][p2],sum+=f[w2][p2].w;
                p2++;
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans<<'\n';
    return 0;
}