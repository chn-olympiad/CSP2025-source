#include <bits/stdc++.h>
int a[505];
int cnt = 0;
long long ans = 1;
std::string s;
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    std::cin>>n>>m;
    std::cin>>s;
    for(int i = 1;i <= n;i++) {
        std::cin>>a[i];
        if(!a[i]) {
            cnt++;
        }
    }
    for(int i = 2;i <= cnt;i++) {
        ans *= i;
        ans %= 998244353;
        std::cout<<ans<<" ";
    }
    return 0;
}
