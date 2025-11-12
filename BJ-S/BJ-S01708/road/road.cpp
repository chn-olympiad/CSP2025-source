#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
#define int long long
const int N=10005,K=12;
int n,m,k,fa[N+25],sz[N+25],ans=0,sum=0;
int c[K+5],a[K][N+5];
struct edge{
    int v,w;
};
struct E{
    int u,v,w;
};
struct F{
    int u,v,w,from;
}e[4000005];
int CC;
vector<edge> Adj[N];
vector<E> tree,bg;

int find(int x){
    return (fa[x]==x?x:fa[x]=find(fa[x]));
}

void merge(int u,int v){
    u=find(u),v=find(v);
    if(u==v) return ;
    if(sz[u]<sz[v]) swap(u,v);
    fa[v]=u;
    sz[u]+=sz[v];
}

bool cmp(E x,E y){
    return x.w<y.w;
}

bool cmp2(F x,F y){
    return x.w<y.w;
}

void BUILD(){
    _for(i,1,n+k+1) sz[i]=1,fa[i]=i;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    _for(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        bg.push_back({u,v,w});
    }


    BUILD();

    _for(i,1,k){
        cin>>c[i];
        _for(j,1,n){
            cin>>a[i][j];
        }
    }

    sort(bg.begin(),bg.end(),cmp);
    int fk=0;
    for(auto i:bg){
        int U=i.u,V=i.v,W=i.w;
        if(find(U)!=find(V)){
            merge(U,V);
            ans+=W;
            tree.push_back({U,V,W});
            fk++;
        }
        if(fk==n-1) break;
    }
    _rep(S,(1<<k)-1,(1<<k)){
        _rep(i,0,k){
            if((1<<i)&S){
                _for(j,1,n){
                    e[++CC]={i+n+1,j,a[i+1][j],i+n+1};
//                    e.push_back();
                }
            }
        }
    }
    for(auto i:tree) e[++CC]={i.u,i.v,i.w,325724};
    sort(e+1,e+CC+1,cmp2);


    _rep(S,0,(1<<k)){
        BUILD();
        sum=0;
        _rep(i,0,k){
            if((1<<i)&S){
                sum+=c[i+1];
            }
        }
        int szzz=0;
        _for(KK,1,CC){
            F i=e[KK];
            if(((1<<(i.from-1-n))&S)||i.from==325724)
            {
                int U=i.u,V=i.v,W=i.w;
                if(find(U)!=find(V)){
                    merge(U,V);
                    sum+=W;
                    szzz++;
                }
            }
        }
       // cout<<szzz+n-1<<' '<<S<<'\n';
        //cout<<sum<<'\n';
//        assert(szzz==all+n-1);
        ans=min(ans,sum);
    }
    cout<<ans<<'\n';
    return 0;
}
