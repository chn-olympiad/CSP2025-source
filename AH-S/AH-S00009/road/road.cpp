#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+100,M=1e6+100;
struct Edge{
    ll u,v,w;
}e[M*2];
ll n,m,k,fa[N],cnt;
ll c[50],a[50][N],ans;
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
void add(ll x,ll y,ll z){
    e[++cnt]={x,y,z};
}
ll get_fa(ll x){
    if(fa[x]==x) return x;
    return get_fa(fa[x]);
}
void kruskal()
{
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=cnt;i++){
        ll x=get_fa(e[i].u),y=get_fa(e[i].v);
        // cout<<e[i].u<<" "<<x<<" "<<e[i].v<<" "<<y<<endl;
        if(x==y) continue;
        ll res=e[i].w,id=0;
        for(int j=1;j<=k;j++){
            ll val=a[j][x]+a[j][y]+c[j];
            if(res > val){
                res=val;
                id=j;
            }
        }
        if(id!=0){
            // cout<<x<<" "<<y<<" "<<id<<" "<<a[id][y]<<" "<<a[id][x]<<" "<<c[id]<<endl;
            c[id]=0;
            a[id][y]=0;
            a[id][x]=0;
            
        }
        ans+=res;
        for(int j=1;j<=k;j++){
            a[j][y]=min(a[j][x],a[j][y]);
        }
        
        fa[x]=y;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    kruskal();
    cout<<ans<<endl;
    return 0;
}