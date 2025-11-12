#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if(m == 1){
        int a[505];
        unsigned long long ans = 0;
        string ab;
        cin >> ab;
        for(int i = 0;i < n;i++){
            cin >> a[i];
            unsigned long long cnt = 1;
            for(int i = 1;i <= n-1;i++){
                cnt *= i;
            }
            ans += cnt * max(0, a[i]);
        }
        cout << ans <<'\n';
        return 0;
    } else if(m == n){
        int a[505], ans = 0;
        string ab;
        cin >> ab;
        for(int i = 0;i < n;i++){
            if(ab[i] == '0') return cout << 0 <<'\n', 0;
        }
        cout << 1 << '\n';
        return 0;
    } if(1){
        int a[505], ans = 0;
        string ab;
        cin >> ab;
        for(int i = 0;i < n;i++){
            if(ab[i] == '1') ans++;
        }
        if(ans < m) return cout << 0 <<'\n', 0;
    }
    unsigned long long ans = 1;
    for(int i = 0;i < m;i++){
        ans *= n-i;
        ans %= 998244353;
    }
    cout << ans <<'\n';
    return 0;
}
