#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll a[500005];
ll s[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        s[i]=s[i-1]^a[i];
    }
    ll sum=0;
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            if((s[j]^s[i-1])==k){
                i=j;
                sum++;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
