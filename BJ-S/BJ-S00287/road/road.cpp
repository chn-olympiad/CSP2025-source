#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,siz;
ll c[11];
ll fa[10021];
struct node{
    ll l,r,v;
}lids[3000001],a[11][10001];
ll f[10001][11];
ll minn[10001][11];
ll sump[1024];
vector<node> vec[10001];
ll find(ll x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
    return x.v<y.v;
}
vector<node> g;
ll plu[1026];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >>n >>m >>k;
    for(int i=1;i<=m;i++){
        cin >>lids[i].l >>lids[i].r >>lids[i].v;
    }
    siz=(1<<k)-1;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=k;i++){
        cin >>c[i];
        for(int j=1;j<=n;j++) cin >>a[i][j].v,a[i][j].l=i+n,a[i][j].r=j;
    }
    sort(lids+1,lids+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(find(lids[i].l)!=find(lids[i].r)){
            fa[find(lids[i].l)]=find(lids[i].r);
            g.push_back({lids[i]});
        }
    }
    for(int i=0;i<=siz;i++){
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1) plu[i]+=c[j];
        }
    }
    ll ans=2e18;
    ll cur=0;
    for(int ds=0;ds<=siz;ds++){
        cur=0;
        ll sum=plu[ds];
        for(int i=1;i<n;i++) lids[++cur]=(g[i-1]);
        for(int i=1;i<=n+k;i++){
            fa[i]=i;
        }
        for(int j=1;j<=k;j++){
            if((ds>>(j-1))&1){
                for(int i=1;i<=n;i++) lids[++cur]=(a[j][i]);
            }
        }
        sort(lids+1,lids+1+cur,cmp);
        ll nowsiz=cur;
        ll flag=0;
        //for(int i=0;i<cur;i++) cout <<lids[i]
        for(int i=1;i<=nowsiz && !flag;i++){
            node ps=lids[i];
            ll l=ps.l,r=ps.r,val=ps.v;
            if(find(l)==find(r)) continue;
            fa[find(l)]=r;
            sum+=val;
            if(sum>ans) flag=1;
        }
        if(!flag)ans=min(ans,sum);
    }
    cout <<ans;
    return 0;
}
