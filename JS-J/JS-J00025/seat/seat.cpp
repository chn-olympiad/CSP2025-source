#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define str string
#define bstr basic_string
int main(){
    #ifndef DXX_DEBUG
        freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
    #endif
    ll n,m,Rv,Rw;
    cin>>n>>m;
    vec<ll>vs;
    cin>>Rv;
    vs.push_back(Rv);
    for(ll i=1;i<n*m;i++){
        ll v;
        cin>>v;
        vs.push_back(v);
    }
    sort(vs.rbegin(),vs.rend());
    for(ll i=0;i<n*m;i++){
        if(vs[i]==Rv){
            Rw=i;
            break;
        }
    }
    ll l=(Rw+n)/n;
    ll r=(Rw)%n;
    r++;
    if(l%2==0)r=n-r+1;
    cout<<l<<' '<<r<<'\n';
    return 0;
}
