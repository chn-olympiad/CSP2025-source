#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c,ans=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c;
    for(int i=1;i<=n;i++){
        ans=((ans%mod)*(i%mod))%mod;
    }
    cout<<ans%mod;
    return 0;
}
