#include <bits/stdc++.h>
using namespace std;
int n,m,ans=1;
const int q=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        ans*=(i%q);
        ans%=q;
    }
    cout<<ans;
    return 0;
}
