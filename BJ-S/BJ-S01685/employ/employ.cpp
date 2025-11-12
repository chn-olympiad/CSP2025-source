#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    long long ans=1;
    for(int i=2;i<=n;i++)ans=1ll*ans*i%mod;
    cout<<ans;
    return 0;
}

