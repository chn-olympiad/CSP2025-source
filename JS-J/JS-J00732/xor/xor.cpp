#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500050],ans,c;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        c=a[i];
        if(c==k){
            //cout<<i<<" "<<i<<" ";
            ans++;
            i++;
        }
        for(ll j=i+1;j<=n;j++){
            c=(c^a[j]);
            if(c==k){
                //cout<<i<<" "<<j<<" ";
                ans++;
                i=j+1;
                j=n+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
