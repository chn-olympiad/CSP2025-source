#include <bits/stdc++.h>

using namespace std;

int grid[10][10], nums[100];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n * m; ++i) {
        cin >> nums[i];
    }
    int r = nums[0];
    sort(nums, nums + n * m);
    reverse(nums, nums + n * m);
    int idx = 0;
    for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                grid[j][i] = nums[idx++];
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                grid[j][i] = nums[idx++];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == r) {
                cout << j + 1 << " " << i + 1 << endl;
            }
        }
    }
    return 0;
}
