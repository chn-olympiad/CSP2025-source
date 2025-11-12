#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

ll n,m;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);

    cin >> n >> m;

    ll ans=1;
    for(int i=1;i<=n;i++){
        ans = ans*i%mod;
    }
    cout << ans<<endl;
}
