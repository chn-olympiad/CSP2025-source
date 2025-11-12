/*
luogu uid: 1054383

exception: 100pts
*/

#include <bits/stdc++.h>

const int md(998244353);

int n;

int a[5000+5];

int cnt[5000+5];

int self[5000+5];

int sum;

int ans;

int main() {
    std::freopen("polygon.in", "r", stdin);
    std::freopen("polygon.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin>>n;
    for(int i(1); i<=n; i++) std::cin>>a[i];
    std::sort(a+1, a+n+1);
    cnt[0]=1;
    for(int i(1); i<=n; i++) {
        for(int j(a[i]+1); j<=std::min(sum, 5001); j++) ans=(ans+cnt[j]-self[j])%md;
        for(int j(std::min(sum, 5001)); j>=0; j--) {
            int to(std::min(j+a[i], 5001));
            cnt[to]=(cnt[j]+cnt[to])%md;
        }
        self[a[i]]++;
        sum+=a[i];
    }
    std::cout<<ans;
    return 0;
}