#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w"stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int ans=1;
    for(int i=1;i<=n;i++){
    	ans=ans*i%mod;
    }
    cout<<ans;
    return 0;
}
