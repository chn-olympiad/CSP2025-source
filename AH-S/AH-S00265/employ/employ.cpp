#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[100006];
long long jiec(long long x){
    long long ans=1;
    for(long long i=1;i<=x;i++){
        long long y=i;
        ans=(ans%mod*y%mod)%mod;
    }
    return ans%mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    long long ans=0;
    cin>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=m;i<=n;i++)
        ans+=jiec(i)%mod;
    cout<<ans%mod;
    return 0;
}
