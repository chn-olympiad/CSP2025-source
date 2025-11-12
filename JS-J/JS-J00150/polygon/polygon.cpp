#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 998244353;
int n, a[5005], maxn = -1;
ll jc(int m){
    if (m == 1 || m == 0) return 1;
    return m % M * jc(m - 1) % M;
}
ll c(int m, int n){
    return jc(m) % M * jc(m - n) % M / jc(n) % M;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxn = max(a[i], maxn);
    }
    ll s = 0;
    sort(a + 1, a + n + 1);
    if (maxn == 1){
        for (int i = 3; i <= n; ++i){
            s += c(n, i) % M;
            s %= M;
        }
    }
    else if (maxn <= 10){
        if (a[1] + a[2] > a[3]) s = 1;
        else s = 0;
    }
    cout << s;
    return 0;
}
