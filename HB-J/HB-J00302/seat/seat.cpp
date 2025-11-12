#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[105];
void solve(){
    ll n,m,r;
    cin>>n>>m;
    cin>>r;
    a[1]=r;
    for(int i=2;i<=n*m;i++) cin>>a[i];
    sort(a+1,a+(n*m)+1,greater<ll>());
    ll s=lower_bound(a+1,a+1+(n*m),r,greater<ll>())-a;
    if(s%n==0){
        cout<<s/n<<" "<<n;
    }else{
        cout<<s/n+1<<" ";
        if((s/n+1)%2==0) cout<<n-s%n+1;
        else cout<<s%n;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
