#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[105];
void solve(){
    int n,m;
    cin>>n>>m;
    int ans{};
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int it{1};
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            it++;
        }
    }
    // cout<<it;
    int mod=it%n,div=it/n;
    if(mod==0)div--,mod=n;
    cout<<div+1;
    if(div&1){
        cout<<' '<<n-mod+1;
    }else{
        cout<<' '<<mod;
    }
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}