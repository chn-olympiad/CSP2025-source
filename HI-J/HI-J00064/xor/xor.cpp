#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> nums;
vector<set<int>> inter;
vector<int> result;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        nums.push_back(a);
    }
    for (int l = 0; l < n; l++) {
        for (int r = 0; r < n; r++) {
            int xor_ = nums[l];
            set<int> tmp;
            for (int i = l+1; i <= r; i++) {
                xor_ ^= nums[i];
            }
            for (int i = l; i <= r; i++) {
                tmp.insert(i);
            }
            inter.push_back(tmp);
            result.push_back(xor_);
        }
    }
    int cnt = 0;
    vector<set<int>> selected;
    for (int i = 0; i < n; i++) {
        if (result[i] != k) {
            selected.push_back(inter[i]);
        }
    }
    int selSize = selected.size();
    for (int i = 2; i <= selSize; i++) {
        int times = i;
        int power = pow(selSize, i);
        set<int> pairs[power][i];
        while (times--) {
            for (int j = 0; j < selSize; j++) {
                pairs[j][i - times - 1] = selected[selSize];
            }
        }
        for (int j = 0; j < power; j++) {
                set<int> res = pairs[j][0];
            for (int k = 1; k < i; k++) {
                res &= pairs[j][k]
            }
            if (res.size() == 0) cnt++;
        }
    }
    cout << cnt;
    return 0;
}