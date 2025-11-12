#include<stdio.h>
#include<algorithm>
#include<numeric>
#include<tuple>
typedef long long ll;
constexpr int N{10000},M{1000000},K{10};
template<int _N>
struct union_find {
    int fa[_N+5];
    void initialize(const int &n) {
        std::iota(fa,fa+n,0);
    }
    int getf(const int &x) {
        return fa[x]==x?x:fa[x]=getf(fa[x]);
    }
    bool merge(int x,int y) {
        if((x=getf(x))==(y=getf(y))) {
            return false;
        }
        return fa[y]=x,true;
    }
};
using edge=std::tuple<int,int,int>;
edge rd[M+5],rd2[1<<K][N+5];
ll cost[1<<K];
edge tmp[(N+K<<1)+5];
union_find<N+K> dsu;
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i!=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        rd[i]=edge(w,u-1,v-1);
    }
    std::sort(rd,rd+m);
    dsu.initialize(n);
    for(int i=0,j=0;i!=m;i++) {
        if(dsu.merge(std::get<1>(rd[i]),std::get<2>(rd[i]))) {
            rd2[0][j++]=rd[i];
        }
    }
    cost[0]=0;
    for(int i=0;i!=k;i++) {
        int w;
        scanf("%d",&w);
        cost[1<<i]=w;
        for(int j=0;j!=n;j++) {
            scanf("%d",&w);
            rd2[1<<i][j]=edge(w,n+i,j);
        }
        std::sort(rd2[1<<i],rd2[1<<i]+n);
    }
    auto merge([&](edge *const x,const int &sx,edge *const y,const int &sy,edge *const z)->void {
        std::merge(x,x+sx,y,y+sy,tmp);
        dsu.initialize(n+k);
        for(int i=0,j=0;i!=sx+sy;i++) {
            if(dsu.merge(std::get<1>(tmp[i]),std::get<2>(tmp[i]))) {
                z[j++]=tmp[i];
            }
        }
    });
    ll ans{0};
    for(int i=0;i!=n-1;i++) {
        ans+=std::get<0>(rd2[0][i]);
    }
    for(int i=1;i!=1<<k;i++) {
        int _i{i&-i},_c{__builtin_popcount(i)};
        merge(rd2[i^_i],n-1+_c-1,rd2[_i],n,rd2[i]);
        cost[i]=cost[i^_i]+cost[_i];
        ll sum{cost[i]};
        for(int j=0;j!=n-1+_c;j++) {
            sum+=std::get<0>(rd2[i][j]);
            auto &[w,u,v](rd2[i][j]);
        }
        ans=std::min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}