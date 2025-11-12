#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll s[500005];
ll l=1,r=1;
ll sum,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    while(r<=n){
        bool flag=0;
        for(ll i=l-1;i<r;i++){
            if((s[r]^s[i])==m){
                r++;
                l=r;
                flag=1;
                break;
            }
        }
        if(flag) ans++;
        else r++;
    }
    cout<<ans;
    return 0;
}