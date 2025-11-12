#include <bits/stdc++.h>
using namespace std;
unsigned long long n;
const unsigned long long mod = 998244353;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    cout << ((n - 2) * (n - 2) - (n - 3) * (n - 2) / 2) % mod;
    return 0;
}
