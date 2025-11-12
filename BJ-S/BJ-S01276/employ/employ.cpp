#include <bits/stdc++.h>
using namespace std;
const long long N = 998244353;
int n , m , ed;
string s;
int a[501];
int c[501];
long long ans;
long long sum[501] = {1};
int main(){
    freopen("employ.in" , "w" , stdin);
    freopen("employ.out" , "r" , stdout);
    cin >> n >> m >> s;
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        c[a[i]] ++;
        sum[i] = sum[i - 1] * i % N;
    }
    ed = s.find('0') + 1;
    for (int i = m ; i <= ed ; i ++){
        ans += sum[i];
        ans %= N;
    }
    cout << ans;
    return 0;
}