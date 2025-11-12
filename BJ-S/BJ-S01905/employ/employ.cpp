#include <bits/stdc++.h>
using namespace std;

int mod = 998244353;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n, m;
    cin >> n >> m;
    int o;
    cin >> o;
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
    }
    long long ans = 1;
    for(int i = 1;i <= n;i++){
        ans = (ans*i)%mod;
    }
    cout << ans;
    return 0;
}