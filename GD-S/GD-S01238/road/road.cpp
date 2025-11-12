#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sl static inline
const int maxm = 1e6+7,maxn=1e4+7;
int n,m,k;
struct R{
    int u,v,w;
    inline bool operator<(const R&o)const{
        return w<o.w;
    }
}r[maxm];
struct C{
    int w;
    int cw[maxn];
}c[17];

int bcj[maxm];

sl ll find(ll n){
    if(bcj[n]==n)return n;
    return bcj[n]=find(bcj[n]);
}

sl bool same(ll a,ll b){
    return find(a)==find(b);
}

sl void merge(ll a,ll b){
    bcj[find(a)]=find(b);
}

static inline bool checkA(){
    if(k==0)return false;
    for(int i=1;i<=k;i++){
        if(c[i].w!=0)return false;
    }
    vector<R> vr(r+1,r+1+m);
    for(int i=1;i<=k;i++){
        for(ll j=1;j<n;j++){
            for(ll k=j+1;k<=n;k++){
                vr.push_back({j,k,c[i].cw[j]+c[i].cw[k]});
            }
        }
    }
    for(int i=1;i<=n;i++)bcj[i]=i;
    sort(vr.begin(),vr.end());
    ll ans=0;
    for(int i=0;i<vr.size();i++){
        if(same(vr[i].u,vr[i].v))continue;
        ans+=vr[i].w;
        merge(vr[i].u,vr[i].v);
    }
    cout<<ans<<"\n";
    return true;
}


static inline bool checkB(){
    if(k!=0)return false;
    for(int i=1;i<=n;i++)bcj[i]=i;
    sort(r+1,r+1+m);
    ll ans=0;
    for(int i=1;i<=m;i++){
        if(same(r[i].u,r[i].v))continue;
        ans+=r[i].w;
        merge(r[i].u,r[i].v);
    }
    cout<<ans<<"\n";
    return true;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>r[i].u>>r[i].v>>r[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i].w;
        for(int j=1;j<=n;j++){
            cin>>c[i].cw[j];
        }
    }
    if(checkA()){
        return 0;
    }
    if(checkB()){
        return 0;
    }
}