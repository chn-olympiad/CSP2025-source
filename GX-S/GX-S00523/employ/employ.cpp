#include <bits/stdc++.h>
using namespace std;
const int N=510;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*i%998244353;
    }
    cout<<ans%998244353;
    return 0;
}
//yi ti bu hui
//ying gai da bu liao NOIP le
// QwQ
//liu ge ji nian ba
// AFO
