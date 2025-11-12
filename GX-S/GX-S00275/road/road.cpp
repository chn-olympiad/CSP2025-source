#include<iostream>
using namespace std;
using ll=long long;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,m,k;
    ll u[100005],v[10005],a[100005];
    cin>>n>>m>>k;
    ll c[15],a[15][15];
    ll q[10005]={0};
    for(ll i=1;i<=0;i++){
        cin>>u[i]>>v[i]>>a[i];

    }
    for(ll i=1;i<=k;i++)}{
        cin>>c[i];
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            q[i]+=a[i][j];
        }
        q[i]+=c[i];
    }
    ll sum=0;
    for(ll i=1;i<=k;i++){
        if(q[i]<=k)
    }
    cout<<q[k];
    return 0;
}

