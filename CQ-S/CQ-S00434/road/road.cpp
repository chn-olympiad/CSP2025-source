#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{
    constexpr int maxn=1e4+3,maxm=1e6+3,maxk=10;typedef long long ll;
    class edge{
        public:int u,v,w;constexpr edge():u(0),v(0),w(0){}
        constexpr edge(int u,int v,int w):u(u),v(v),w(w){}
        inline bool operator<(const edge&comp)const{return w<comp.w;}
        inline friend ostream&operator<<(ostream&output,const edge&arg)
            {return output<<'{'<<arg.u<<' '<<arg.v<<' '<<arg.w<<'}';}
    }e[maxm],base[maxn],upg[maxn*maxk];int par[maxn+maxk],cost[maxk+3];
    inline int find(int u){static int sta[maxn];
        int top=0;while(par[u]>0)sta[++top]=u,u=par[u];
        while(--top>0)par[sta[top]]=u;return u;
    }
    inline void merge(int u,int v){
        if((u=find(u))==(v=find(v)))return;
        if(par[u]<par[v])par[u]+=par[v],par[v]=u;else par[v]+=par[u],par[u]=v;
    }
    inline int Main(){
        int n,m,k;cin>>n>>m>>k;for(int i=1;i<=m;++i)cin>>e[i].u>>e[i].v>>e[i].w;
        int upg_tot=0;for(int i=1;i<=k;++i){cin>>cost[i];
            for(int j=1,c;j<=n;++j)cin>>c,upg[++upg_tot]=edge(i,j,c);}
        sort(upg+1,upg+upg_tot+1),sort(e+1,e+m+1),memset(par,-1,sizeof(par));
        int count=0;ll ans=0;for(int i=1;i<=m&&count!=n-1;++i)if(find(e[i].u)
            !=find(e[i].v))merge(e[i].u,e[i].v),base[++count]=e[i],ans+=e[i].w;
        for(int i=1;i<1<<k;++i){ll sum=0;count=0;
            for(int j=1;j<=k;++j)if(i>>j-1&1&&(--count,(sum+=cost[j])>=ans))break;
            memset(par,-1,sizeof(par));int iter=1;for(int j=1;j<n;++j){
                while(iter<=upg_tot&&upg[iter].w<base[j].w){if(i>>upg[iter].u-1&1&&
                    find(n+upg[iter].u)!=find(upg[iter].v)){merge(n+upg[iter].u,upg[iter].v);
                        if((sum+=upg[iter].w)>=ans)break;if(++count==n-1){ans=sum;break;}
                    }++iter;}
                if(find(base[j].u)!=find(base[j].v)){merge(base[j].u,base[j].v);
                    if((sum+=base[j].w)>=ans)break;if(++count==n-1){ans=sum;break;}}}}
        cout<<ans<<'\n';return 0;
    }
}
int main(){//clock_t now=clock();
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    SOLUTION::Main();
    /*clog<<"used time: "<<double(clock()-now)/CLOCKS_PER_SEC<<'\n';*/return 0;
}