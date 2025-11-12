#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll ans;
struct node{
    ll to,w;
};
vector<node>e[1010];
ll c[10],a[1010][10];
ll f[1010];
struct rnode{
    ll u,v,w;
}e1[(int)1e6+10];
bool cmp(rnode x,rnode y){
    return x.w<y.w;
}
ll find(ll x){
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        e1[i]={u,v,w};
    }
    bool isA=1;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0)isA=0;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]!=0)isA=0;
        }
    }
    //ll ans=0;
    if(k==0)isA=0;
    if(isA){
        cout<<0;
        return 0;
    }
    if(k==0){
        for(int i=1;i<=n;i++)f[i]=i;
        sort(e1+1,e1+m+1,cmp);
        for(int i=1;i<=m;i++){
            if(find(e1[i].u)!=find(e1[i].v)){
                f[find(e1[i].u)]=find(e1[i].v);
                ans+=e1[i].w;
            }
        }
        cout<<ans;


    }
    return 0;
}
