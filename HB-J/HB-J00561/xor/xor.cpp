#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    //ll c=a[1]^a[2]^a[3];
    ll ans=0;
    for(ll i=0,j=0;i<n;i++){
        ll c=0;
        for(ll k=j;k<=i;k++){
            c=c^a[k];
        }
        if(c==k){
            ans++;
            j=i+1;
        }
    }
    cout<<ans;
    return 0;
}