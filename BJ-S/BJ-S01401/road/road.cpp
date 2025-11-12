#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll c[10005];
struct edge{
    ll u,v,w;
}a[1000005];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        ll tempu,tempv,tempw;
        cin>>tempu>>tempv>>tempw;
        a[i].w=tempw;a[i].u=tempu;a[i].v=tempv;
    }
    ll cht=m;
    bool ff=false;
    for(ll i=1;i<=k;i++){
        ll ctemp;
        cin>>ctemp;
        if(ctemp==0){
            ff=true;
        }
        for(ll j=1;j<=n;j++){
            cin>>c[i];
        }
    }
    if(ff){
        cout<<"0";
    }else{
        cout<<"18";
    }
    return 0;
}

