#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+5;
const ll M=1e7+5;
priority_queue< pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q[11];
ll n,m,k;
ll he[M],to[M],ne[M],ww[M],fr[M],cnt;
ll fa[M];
ll stp[15];
ll ans;
ll fnd(ll x){
    if(x==fa[x]) return x;
    //fnd(fa[x]);
    fa[x]=fnd(fa[x]);
    return fa[x];
}
ll check(ll x,ll y){
    //cout<<x<<" "<<y<<endl;
    if(fnd(x)==fnd(y)) return 1;
    else return 0;

}
void uion(ll x,ll y){
    fa[fnd(x)]=fnd(y);
    //cout<<"!"<<x<<" "<<y<<endl;
}
void addedge(ll u,ll v,ll w){
    ne[++cnt]=he[u];
    to[cnt]=v;
    fr[cnt]=u;
    he[u]=cnt;
    ww[cnt]=w;
    //cout<<u<<" "<<v<<" "<<w<<endl;
}
ll kua1(ll x){
    for(ll i=0;i<=n+k;i++){
            fa[i]=i;
    }
    ans=0ll;
    for(ll i=he[0];i;i=ne[i]){
        if(to[i]>n+x) continue;
        uion(0,to[i]);
        //cout<<to[i]<<" "<<endl;
        ans+=ww[i];
    }
    //cout<<stp[x]<<endl;
    for(ll i=1;i<=stp[x];i++){
        q[x].push({ww[i],i});
    }
    int sz=0;
    while(!q[x].empty()){
        if(sz==n+x) break;
        ll ys=q[x].top().second;
        q[x].pop();
        if(!check(fr[ys],to[ys])){
                sz++;
            uion(fr[ys],to[ys]);
            ans+=ww[ys];
            //cout<<x<<" "<<ww[ys]<<endl;
        }
        //cout<<ans<<" ";
    }
    //cout<<ans;
    //cout<<endl<<endl;
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=0;i<=n+k;i++){
        fa[i]=i;
    }
    ll u,v,w;
    for(ll i=1;i<=m;i++){
        cin>>u>>v>>w;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    stp[0]=cnt;
    ll wx;
    for(ll i=1;i<=k;i++){
        cin>>wx;
        addedge(0,n+i,wx);
        //addedge(n+i,0,wx);
        int wy;
        for(ll j=1;j<=n;j++){
            cin>>wy;
            addedge(n+i,j,wy);
            addedge(j,n+i,wy);
        }
        stp[i]=cnt;
    }
    ll ans1=LONG_MAX;
    for(ll i=0;i<=k;i++){

            //cout<<i<<"?"<<stp[i]<<endl;
        ans1=min(kua1(i),ans1);
        //cout<<kua1(i)<<"!"<<endl;
    }

    //int ans2=kua2();
    cout<<ans1;//ans2!!
    return 0;
}
