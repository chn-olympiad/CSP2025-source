#include <bits/stdc++.h>

#define rep(i,l,r) for(auto i(l);i<=r;++i)
#define per(i,l,r) for(auto i(r);i>=l;--i)
#define ls(p) ((p)<<1)
#define rs(p) ((p)<<1|1)

typedef long long LL;
typedef std::pair<int,int> PII;

const int N = 10030;
const int M = 2000010;
const auto INF = 0x3f3f3f3f3f3f3f3f;

inline LL read(){
    LL x=0;char ch=getchar();bool f=0;
    while(ch<'0' || ch>'9'){f=(ch=='-');ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f?-x:x;
}

int n,m,k;
int c[20],fa[N];
int a[20][N];

struct edge{int u,v,w;};

std::vector<edge> p,d;

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    n=read(),m=read(),k=read();

    rep(i,1,n){fa[i]=i;}

    rep(i,1,m){
        int u=read(),v=read(),w=read();
        p.push_back({u,v,w});
    }

    LL ans=0;

    std::sort(p.begin(),p.end(),[](edge x,edge y){return x.w<y.w;});

    for(auto i : p){
        int x=find(i.u),y=find(i.v);
        if(x==y){continue;}
        fa[x]=y;ans+=i.w;
        d.push_back(i);
    }

    rep(i,1,k){
        c[i]=read();
        rep(j,1,n){
            a[i][j]=read();
        }
    }

    rep(i,0,(1<<k)-1){
        LL res=0;
        p.clear();
        for(auto j : d){p.push_back(j);}
        int num=0,cnt=0;
        rep(j,1,k){
            if(i&(1<<j-1)){
                res+=c[j];
                ++num;
                rep(_,1,n){
                    p.push_back({j+n,_,a[j][_]});
                }
            }
        }
        rep(i,1,n+k){fa[i]=i;}
        std::sort(p.begin(),p.end(),[](edge x,edge y){return x.w<y.w;});
        for(auto j : p){
            int x=find(j.u),y=find(j.v);
            if(x==y){continue;}
            res+=j.w;++cnt;fa[x]=y;
            if(cnt==n+num-1){break;}
        }
        ans=std::min(ans,res);
    }

    printf("%lld\n",ans);

    return 0;
}
/*
-O2 -Wall -static -o
-fsantize=address,undefined -Wall -O2 -o
*/
