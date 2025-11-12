//GZ-S00262,贵州,杨帆乐,520113200802190033,贵阳市南明甲秀高级中学,高三
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#define MAXN 100004
#define ll long long

using namespace std;

ll n,m,k,u,v;
ll ans=0;
//vector<int> eg[MAXN];
ll fa[MAXN];
ll c[MAXN];
vector<pair<ll,ll>> aa[10];

struct edge{
    ll u,v,w;
    bool operator < (const edge &b)const{
        return w<b.w;
    }
};

vector<edge> stk;

inline ll find(ll a){return fa[a]==a?a:fa[a]=find(fa[a]);}

inline void krus(){
    ll cnt=0;
    for(edge k : stk){
        if(cnt>=n-1)break;
        if(find(k.u)!=find(k.v)){
            ans+=k.w;
            //cout<<k.u<<" "<<k.v<<endl;
            //if(k.u<n||k.v<n){cout<<k.u<<" "<<k.v<<endl;}
            fa[find(k.u)]=find(k.v);
            cnt++;
        }else{
            continue;
        }
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        ll u=0,v=0;
        ll w=0;
        cin>>u>>v>>w;
        stk.push_back({u,v,w});
    }

    /*for(auto k:stk){
        if(k.u>n||k.v>n)cout<<k.u<<" "<<k.v<<endl;
    }*/

    for(ll i=1;i<=n;i++){fa[i]=i;}

    /*for(auto k:stk){
        if(k.u>n||k.v>n)cout<<k.u<<" "<<k.v<<endl;
    }*/

    for(ll ii=1;ii<=k;ii++){
        cin>>c[ii];
        for(ll jj=1;jj<=n;jj++){
            ll tt=0;
            cin>>tt;
            aa[ii].push_back({tt,jj});
        }
    }

    /*for(auto k:stk){
        if(k.u>n||k.v>n)cout<<k.u<<" "<<k.v<<endl;
    }*/

    for(ll i=1;i<=k;i++){////
        sort(aa[i].begin(),aa[i].end());
    }

    //sort(stk.begin(),stk.end());

    /*for(auto k:stk){
        if(k.u>n||k.v>n)cout<<k.u<<" "<<k.v<<endl;
    }*/

    for(ll o=1;o<=k;o++){
        ll cntn = 0;
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                ll uu=aa[o][i].second,vv=aa[o][j].second;
                if(i+2<n&&(aa[o][i].first+aa[o][j].first>aa[o][i+1].first+aa[o][i+2].first))break;
                cntn++;
                //if(uu<=0||vv<=0){cout<<uu<<" "<<vv<<endl;}
                stk.push_back({uu,vv,c[o]+aa[o][i].first+aa[o][j].first});
                //if(stk.back().u>n||stk.back().v>n){cout<<uu<<" "<<vv<<endl;}
                if(cntn>=n-1)break;
            }
            if(cntn>=n-1)break;
        }
    }

    /*for(auto k:stk){
        if(k.u>n||k.v>n)cout<<k.u<<" "<<k.v<<endl;
    }*/

    sort(stk.begin(),stk.end());

    /*for(auto k:stk){
        if(k.u>n||k.v>n)cout<<k.u<<" "<<k.v<<endl;
    }*/

    krus();

    cout<<ans<<endl;
}
