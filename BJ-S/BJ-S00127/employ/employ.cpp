#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mod = 998244353,ans = 1;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        ans *= i;
    }
    cout << ans;
    return 0;
}
