#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[5003], ans;
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i = 1;i <= n;i++)cin>>a[i];
    for(int mask = 0;mask < (1 << n);mask++){
        int cnt = 0, sum = 0, mx = 0;
        for(int i = 0;i < n;i++){
            int x = (mask >> i) & 1;
            if(x)cnt++, sum += a[i + 1], mx = max(mx, a[i + 1]);
        }
        if(cnt >= 3 && sum > 2 * mx)ans = (ans + 1) % 998244353;
    }
    cout<<ans;
}
