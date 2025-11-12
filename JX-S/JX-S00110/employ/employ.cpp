#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,ans=1;
long long a(long long n,long long m){
    for(long long i=m;i<=n;i++){
        ans=ans*i%mod;
    }
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cout<<a(n,m);
    return 0;
}
