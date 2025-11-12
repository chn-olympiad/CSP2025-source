#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+6,mod=998244353;
int n;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n;
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    cout << ans;
    return 0;
}
