#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n,k;
string s;

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> k;
    cin >> s;

    int fac = 1;

    for(int i = 2; i <= n; i++){
        fac = fac*i %MOD;
        cout <<fac<<" ";
    }
    cout  <<fac%MOD;
    return 0;
}
