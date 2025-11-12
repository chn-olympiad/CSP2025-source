#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int n;
int arr[3+(int)5e5], k, x[3+(int)5e5], dp[3+(int)5e5];

std::vector<int> un[1<<21];

struct len {
    int left, right;
    bool operator< (const len& rhs) const {
        if(right != rhs.right) return right < rhs.right;
        return left < rhs.left;
    }
};

std::vector<len> v;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    for(int i=1;i<=n;i++) {
        std::cin >> arr[i];
        x[i]=(x[i-1]^arr[i]);
        un[x[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) {
        int need=x[i-1]^k;
        if(un[need].empty()) continue;
        std::vector<int>::iterator found=std::lower_bound(un[need].begin(), un[need].end(), i);
        if(found==un[need].end()) continue;
        v.push_back({i, *found});
    }
    std::sort(v.begin(), v.end());
    int point=0, ans=0;
    for(int i=0;i<v.size();i++) {
        if(point < v[i].left) {
            ++ans;
            point=v[i].right;
        }
    }
    std::cout << ans;
}
