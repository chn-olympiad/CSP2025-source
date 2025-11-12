#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10];
void solve(){
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1) cout<<1;
    else if(a[1]==0&&a[2]==0) cout<<2;
    else if(a[1]^a[2]==0) cout<<1;
    else cout<<0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
