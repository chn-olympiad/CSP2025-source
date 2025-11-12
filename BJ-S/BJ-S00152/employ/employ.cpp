#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
long long ans;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
    long long ans;
        for(long long i=1;i<=n;i++) ans*=i,ans%=mod;
        cout<<ans<<endl;
}
