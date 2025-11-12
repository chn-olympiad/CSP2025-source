#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500005],cnt;
//vector<ll> v;
void solve(){
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n%2==0) cout<<n/2;
    else cout<<(n-1)/2;
    return ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
