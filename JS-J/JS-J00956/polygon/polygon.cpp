#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
ll n,a[N],ma;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        ma=max(a[i],ma);
    }
    if(n==3){
        ll mad,s=0;
        for(int i=1;i<=n;i++){
            ma=max(ma,a[i]);
            mad=i;
            s+=a[i];
        }
        if(s>ma*2) cout<<1;
        else cout<<0;
        return 0;
    }
    if(ma==1){
        ll ans=(n-1)*(n-2)/2;
        cout<<ans%998244353;
    }
    return 0;
}
