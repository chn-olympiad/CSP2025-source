#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int t,n,m,a[505],ans=1;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    cout<<ans%mod;
    return 0;
}