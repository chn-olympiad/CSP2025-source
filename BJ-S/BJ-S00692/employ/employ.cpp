#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    string s;
    cin >> n >> m >> s;
    long long ans = 1;
    for(int i = m; i >= 1; i--){
        ans = (ans * i) % mod;
    }
    cout << ans << endl;
    return 0;
}
