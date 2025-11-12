#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define debug
ll c[15];
ll a[15][10050];
struct node{
    ll u,v,w;
}mp[2200050],b[2200050];
ll cnt;
bool cmp(node a,node b){
    return a.w<b.w;
}
ll fa[110050];
void init(ll n){
    for(ll i=1;i<=n;i++)fa[i]=i;
}
ll find(ll p){
    if(fa[p]==p)return p;
    return fa[p]=find(fa[p]);
}
void combine(ll x,ll y){
    fa[find(x)]=find(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,m,K;
    cin>>n>>m>>K;
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        mp[++cnt].u=u;
        mp[cnt].v=v;
        mp[cnt].w=w;
        mp[++cnt].u=v;
        mp[cnt].v=u;
        mp[cnt].w=w;
    }
    for(ll i=1;i<=K;i++){
        cin>>c[i];
        for(ll j=1;j<=n;j++)cin>>a[i][j];
    }
    ll minn=1e9;
    for(ll i=0;i<(1<<K);i++){
        cnt=2*m;
        for(ll j=1;j<=cnt;j++){
            b[j].u=mp[j].u;
            b[j].v=mp[j].v;
            b[j].w=mp[j].w;
        }
        ll ans=0,num=0;
        for(ll j=1;j<=K;j++){
            if(i&(1<<(j-1))){
                ans+=c[j];
                for(ll k=1;k<=n;k++){
                    b[++cnt]={n+j,k,a[j][k]};
                    b[++cnt]={k,n+j,a[j][k]};
                }
            }
        }
        #ifdef debug
        cout<<"cnt:"<<cnt<<endl;
        #endif
        init(n+K);
        sort(b+1,b+cnt+1,cmp);
        #ifdef debug
        for(ll j=1;j<=cnt;j++){
            cout<<b[j].u<<" "<<b[j].v<<" "<<b[j].w<<endl;   
        }
        #endif
        for(ll j=1;j<=cnt;j++){
            ll u=b[j].u,v=b[j].v;
            if(find(u)!=find(v)){
                combine(u,v);
                ans+=b[j].w;
                num++;
            }
        }
        #ifdef debug
        cout<<ans<<endl;
        #endif
        minn=min(minn,ans);
    }
    cout<<minn;
    return 0;
}