#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5010];
long long n, mx = 0, sum = 0, ans = 0;
void f(int x, int id){
    if(x > n){
        return;
    }
    sum += a[x];
    mx = a[x];
    if(sum > mx * 2){
        ans++;
        ans %= mod;
    }
    f(x + 1, x);
    sum -= a[x];
    mx = a[id];
    f(x + 1, id);
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    f(1, 0);
    cout << ans % mod;
    return 0;
}
