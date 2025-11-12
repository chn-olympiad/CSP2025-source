#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
const ll MAXN=10005;
ll n,m,k,cost[10001][11],fa[10001];
struct node{ll u,v,cst;}a[1000001];
ll find(ll x){
    if (fa[x]==x) return x;
    return fa[x]=find(x);
}
void merge(ll x,ll y){fa[find(x)]=y;}
bool cmp(node x,node y){return x.cst<y.cst;}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (ll i=1;i<=n;i++) fa[i]=i;
    fa[3]=4;
    for (ll i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].cst;
    for (ll i=1;i<=k;i++) for (ll j=1;j<=n+1;j++) cin>>cost[i][j];
    if (k==0){
        ll cnt=0;
        sort(a+1,a+m+1,cmp);
        for (ll i=1;i<=m;i++){
            ll x=find(a[i].u);
            if (x!=a[i].v){
                //cout<<fa[find(a[i].u)]<<' '<<a[i].v<<'\n';
                ll y=a[i].v;
                fa[x]=y;
                cnt+=a[i].cst;
            }
        }
        cout<<cnt;
    }
    return 0;
}
