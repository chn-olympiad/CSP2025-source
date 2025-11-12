#include<bits/stdc++.h>
using namespace std;
int n;
const int mod=998244353;
long long ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        ans=ans*i%mod;
    }
    cout<<ans;
    return 0;
}
