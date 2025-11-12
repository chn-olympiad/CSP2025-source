/*
luogu uid: 1054383

exception: ~100pts
*/

#include <bits/stdc++.h>

using pii=std::pair<int, int>;

int n, k;

int a[500000+5];

int x[500000+5];

std::set<int> vals[1<<21];

int m;

pii bs[500000+5];

int dp[500000+5];

int main() {
    std::freopen("xor.in", "r", stdin);
    std::freopen("xor.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin>>n>>k;
    for(int i(1); i<=n; i++) std::cin>>a[i];
    for(int i(1); i<=n; i++) x[i]=a[i]^x[i-1];
    for(int i(1); i<=n; i++) vals[x[i]].insert(i);
    for(int i(1); i<=n; i++) {
        int j(k^x[i-1]);
        if(vals[j].empty() || *(vals[j].rbegin())<i) { continue; }
        bs[++m]={*(vals[j].lower_bound(i)), i};
    }
    std::sort(bs+1, bs+m+1);
    for(int i(1); i<=m; i++) {
        int l(bs[i].second);
        int j(std::upper_bound(bs+1, bs+m+1, pii(l-1, n+5))-bs);
        j--;
        dp[i]=std::max(dp[i-1], dp[j]+1);
    }
    int ans(0);
    for(int i(1); i<=m; i++) ans=std::max(ans, dp[i]);
    std::cout<<ans;
    return 0;
}