#include <bits/stdc++.h>

using namespace std;

int nums[500001];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    unordered_set<int> pre;
    int x = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        pre.insert(x);
        x ^= nums[i];
        if (pre.find(x ^ k) != pre.end()) {
            ++res;
            x = 0;
            pre.clear();
        }
    }
    cout << res << endl;
    return 0;
}
