#include<bits/stdc++.h>
#define ll long long
#define mod 998244353

using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,wait[505];
    ll ans=1;
    char dif[505];
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>dif[i];
    for(int i=1;i<=n;i++)cin>>wait[i];
    for(int i=1;i<=n;i++){
        ans*=2;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
