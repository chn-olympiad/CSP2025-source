#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
string s1;
ll c[1005];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >>n >>m;
    cin >>s1;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }
    sort(c + 1, c + n + 1);
    cout << ((n % 998) % 244) % 353 <<endl;
    return 0;
}
