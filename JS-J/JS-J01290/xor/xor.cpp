#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[550000];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans;
    ll s;
    if(a[1]==k){
        ans=1;
        s=0;
        for(ll i=2;i<=n;i++){
            s=s^a[i];
            if(s==k){
                ans++;
                s=0;
            }
        }
    }
    else{
        ans=0;
        s=0;
        for(ll i=1;i<=n;i++){
            s=s^a[i];
            if(s==k){
                ans++;
                s=0;
            }
        }
    }
    cout<<ans;

    return 0;
}
