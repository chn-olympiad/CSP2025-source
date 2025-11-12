#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=1e4+15,maxm=1e6+5;

int n,m,k,u[maxm],v[maxm],w[maxm];
long long ans=1e16;
int c[15],a[15][maxn];
bool flag;

struct edge{
    int u,v,w,k;

    const bool operator<(edge o)
        {return w<o.w;}
} mp[maxm+maxn*10];

struct ufs{
    int fa[maxn],siz[maxn];
    inline void init()
        {for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;}
    int find(int x){
        return fa[x]==x? x : fa[x]=find(fa[x]);
    }
    void unite(int x,int y){
        static int fx,fy;
        fx=find(x),fy=find(y);
        if(siz[fx]>siz[fy]) fa[fy]=fx,siz[fx]+=siz[fy];
        else fa[fx]=fy,siz[fy]+=siz[fx];
    }
    bool query(int x,int y)
    { return find(x)==find(y);}
}s;

inline void init(){
    s.init();
}

namespace s1{
    inline void solve(){
        init();
        for(int i=0;i<m;i++) mp[i]={u[i],v[i],w[i]};
        sort(mp,mp+m);
        for(int i=0;i<m;i++)
         if(!s.query(mp[i].u,mp[i].v))
          s.unite(mp[i].u,mp[i].v),ans+=mp[i].w;

        printf("%lld",ans);
    }
}
namespace s2{
    long long bas,sum;
    int ecnt;
    bool use[12];
    inline void cal(){
        init();
        sum=0;
        
        for(int i=0;i<ecnt;i++){
            if(!use[mp[i].k]) continue;
            if(!s.query(mp[i].u,mp[i].v))
             s.unite(mp[i].u,mp[i].v),sum+=mp[i].w;
        }

        #ifdef D
        printf("bas:%lld %lld\n",bas,sum+bas);
        fflush(stdout);
        #endif

        ans=min(ans,sum+bas);
    }
    void dfs(int p){
        if(p>k){
            cal();
            return;
        }
        dfs(p+1);
        bas+=c[p],use[p]=1;
        dfs(p+1);
        bas-=c[p],use[p]=0;
    }
    inline void solve(){
        for(int i=0;i<m;i++) mp[i]={u[i],v[i],w[i],0};
        ecnt=m,use[0]=1;
        for(int i=1;i<=k;i++)
            for(int j=1;j<=n;j++) mp[ecnt++]={i+n,j,a[i][j],i};
        sort(mp,mp+ecnt);
        dfs(1);
        printf("%lld",ans);
    }
};

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
    flag=1;
    for(int i=0;i<m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]);
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(c[i]) flag=0;
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    }

    s2::solve();

    return 0;
}