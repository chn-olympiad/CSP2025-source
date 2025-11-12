#include<bits/stdc++.h>
using namespace std;
namespace io{
#define BUFFSIZE 10000000
char buff[BUFFSIZE],*st,*ed;
#define gc() ((st==ed&&(ed=(st=buff)+fread(buff,1,BUFFSIZE,stdin),st==ed))?EOF:*st++);
template <typename T>
inline void read(T &x){
    x=0;
    char c=gc();
    while(!isdigit(c)&&c!=EOF)c=gc();
    while(isdigit(c))x=(x<<1)+(x<<3)+c-'0',c=gc();
}
}
namespace SOLVE{
#define N 10000
#define M 1000000
#define K 10
#define ll long long
struct Edge{
    int u,v,val;
    bool operator < (const Edge &b) const{return val<b.val;}
    bool operator > (const Edge &b) const{return val>b.val;}
}e[M+1];
int n,m,k;
int c[K+1],a[K+1][N+1];
struct bcj{
    int f[N+K+1],rk[N+K+1];
    inline int find(int x){if(!f[x])return x;return f[x]=find(f[x]);}
    inline void linkto(int x,int y){f[x]=y;}
    inline void link(int x,int y){
        int fx=find(x),fy=find(y);
        if(rk[fx]<rk[fy])linkto(fx,fy);
        else if(rk[fx]>rk[fy])linkto(fy,fx);
        else linkto(fx,fy),++rk[fy];
    }
    inline void clear(){memset(f,0,sizeof(f));memset(rk,0,sizeof(rk));}
}b;
void main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    // scanf("%d%d%d",&n,&m,&k);
    io::read(n);io::read(m);io::read(k);
    for(int i=1,u,v,w;i<=m;++i){
        // scanf("%d%d%d",&u,&v,&w);
        io::read(u);io::read(v);io::read(w);
        e[i]=Edge{u,v,w};
    }
    sort(e+1,e+1+m);
    for(int i=1,cur=1;i<=m;++i){
        // auto [u,v,w]=e[i];
        int u=e[i].u,v=e[i].v,w=e[i].val;
        if(b.find(u)==b.find(v))continue;
        b.link(u,v);
        swap(e[cur++],e[i]);
    }
    for(int i=1;i<=k;++i){
        // scanf("%d",&c[i]);
        io::read(c[i]);
        // for(int j=1;j<=n;++j)scanf("%d",&a[i][j]);
        for(int j=1;j<=n;++j)io::read(a[i][j]);
    }
    ll ans=-1;
    for(int s=(1<<k);s--;){
        ll res=0;
        int cnt=0;
        priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
        for(int j=1;j<=k;++j){
            if((s>>j-1)&1){
                res+=c[j];
                ++cnt;
                for(int i=1;i<=n;++i)pq.push(Edge{j+n,i,a[j][i]});
            }
        }
        // for(int i=1;i<n;++i)pq.push(e[i]);
        int cur=1;
        b.clear();
        cnt+=n;
        for(int i=1;i<cnt;++i){
            int u,v,w;
            do{
                int flag=0;
                Edge tmp;
                if(pq.empty())tmp=e[cur++];
                else if(cur>=n||pq.top().val<e[cur].val)flag=1,tmp=pq.top();
                else tmp=e[cur++];
                u=tmp.u;
                v=tmp.v;
                w=tmp.val;
                if(flag)pq.pop();
            }while(b.find(u)==b.find(v));
            res+=w;
            b.link(u,v);
        }
        if(~ans)ans=min(ans,res);
        else ans=res;
    }
    printf("%lld\n",ans);
}
}
int main(){SOLVE::main();return 0;}