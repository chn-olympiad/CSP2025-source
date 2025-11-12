#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;
int n , m;
string s;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);
    cin >> n >> m >> s;
    ll ans = 1;
    for(int i = 1;i <= n;i++) ans = (ans * i) % MOD;
    cout << ans << endl;
    return 0;
}