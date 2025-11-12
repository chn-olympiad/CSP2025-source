/*
luogu uid: 1054383

exception: 100pts
*/

#include <bits/stdc++.h>

int n, m;

int a[100+5];

int x;

int main() {
    std::freopen("seat.in", "r", stdin);
    std::freopen("seat.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin>>n>>m;
    for(int i(1); i<=n*m; i++) std::cin>>a[i];
    x=a[1];
    std::sort(a+1, a+n*m+1, std::greater<int>());
    int now(1);
    for(int i(1); i<=n; i++) {
        for(int j(1); j<=m; j++) {
            if(x==a[now]) {
                std::cout<<i<<" "<<(i%2?j:n-j+1);
            }
            now++;
        }
    }
    return 0;
}