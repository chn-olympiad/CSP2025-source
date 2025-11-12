#include <iostream>
#include <vector>
#include <algorithm>

int n;

int arr[5008];

int ans=0;

void dfs(int step, int max, int sum, int cnt) {
    if(step > n) {
        if(sum > 2*max && cnt >= 3) ++ans;
        return;
    }
    dfs(step+1, max, sum, cnt);
    dfs(step+1, std::max(max, arr[step]), sum+arr[step], cnt+1);
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for(int i=1;i<=n;i++) std::cin >> arr[i];
    dfs(1, 0, 0, 0);
    std::cout << ans;
}
