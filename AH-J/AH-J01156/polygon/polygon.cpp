#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        ll s=a[1]+a[2]+a[3];
        if(s>a[1]*2&&s>a[2]*2&&s>a[3]*2&&n==3) cout<<1;
        else cout<<0;
    }else{
        ll s=0;
        for(ll i=1;i<=n-3+1;i++){
            s+=n-i-2+1;
            s%=998244353;
        }
        cout<<s;
    }
    return 0;
}
