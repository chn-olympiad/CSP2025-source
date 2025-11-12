#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[5500];
ll p=998244353;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>a[3]*2){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    for(ll k=3;k<=n;k++){
        ll he=0;
    }

    return 0;
}
