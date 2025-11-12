#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
using namespace std;

int n,m,k;

ll c[21],a[21][10010];

struct Edge{
    int u,v;
    ll w;
    Edge(){}
    Edge(int uu,int vv,ll ww):u(uu),v(vv),w(ww){}
    friend bool operator < (Edge a,Edge b){
        return a.w>b.w;
    }
}e;

priority_queue<Edge> P;

int fa[10010];

int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}

void merge(int x,int y){fa[find(x)]=find(y);}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        fa[i]=i;
    for(int i=1;i<=m;++i){
        scanf("%d%d%lld",&e.u,&e.v,&e.w);
        P.push(e);
    }
    for(int i=1;i<=k;++i){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;++j){
            scanf("%lld",&a[i][j]);
        }
    }
    if(k!=0){
        for(int l=1;l<=n;++l)
            for(int r=l+1;r<=n;++r){
                ll w=0x7fffffff;
                for(int i=1;i<=k;++i)
                    w=min(w,a[i][l]+a[i][r]);
                P.push(Edge(l,r,w));
            }    
    }
    ll ans=0;
    ll cnt=n;
    while(!P.empty()){
        int ui=P.top().u,vi=P.top().v;
        ll wi=P.top().w;
        P.pop();
        if(find(ui)==find(vi)) continue;
        merge(ui,vi);
        ans+=wi;
        --cnt;
        if(cnt==1){
            break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}


// #include<bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define ppb pop_back
// using namespace std;

// int n,m,k;

// ll c[21],a[21][10010];

// struct Edge{
//     int u,v;
//     ll w;
//     Edge(){}
//     Edge(int uu,int vv,ll ww):u(uu),v(vv),w(ww){}
//     friend bool operator < (Edge a,Edge b){
//         return a.w>b.w;
//     }
// }e;

// priority_queue<Edge> P;

// int fa[10010];

// int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}

// void merge(int x,int y){fa[find(x)]=find(y);}
// int main(){
//     freopen("road.in","r",stdin);
//     freopen("road.out","w",stdout);
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     cin>>n>>m>>k;
//     for(int i=1;i<=n;++i)
//         fa[i]=i;
//     for(int i=1;i<=m;++i){
//         cin>>e.u>>e.v>>e.w;
//         P.push(e);
//     }
//     for(int i=1;i<=k;++i){
//         cin>>c[i];
//         for(int j=1;j<=n;++j){
//             cin>>a[i][j];
//         }
//     }
//     if(k!=0){
//         for(int l=1;l<=n;++l)
//             for(int r=l+1;r<=n;++r){
//                 ll w=0x7fffffff;
//                 for(int i=1;i<=k;++i)
//                     w=min(w,a[i][l]+a[i][r]);
//                 P.push(Edge(l,r,w));
//             }    
//     }
//     ll ans=0;
//     ll cnt=n;
//     while(!P.empty()){
//         int ui=P.top().u,vi=P.top().v;
//         ll wi=P.top().w;
//         P.pop();
//         if(find(ui)==find(vi)) continue;
//         merge(ui,vi);
//         ans+=wi;
//         --cnt;
//         if(cnt==1){
//             break;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }