#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll s=1,k=0;
    cin>>k;
    for(ll i=1;i<n*m;i++){
        ll t;
        cin>>t;
        if(t>k) s++;
    }
    ll c=(s+n-1)/n;
    ll y=s%n;
    if(y == 0) y = n;
    ll r=0;
    if(c%2==1) r = y;
    else r = n-y+1;
    cout<<c<<' '<<r;
    return 0;
}
