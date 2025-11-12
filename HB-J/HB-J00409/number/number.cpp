#include <bits/stdc++.h>

using namespace std;

int nums[10];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    memset(nums, 0, sizeof(nums));
    string s;
    cin >> s;
    for (auto &i: s) {
        if ('0' <= i && i <= '9') {
            ++nums[i - '0'];
        }
    }
    for (int i = 9; i >= 0; --i) {
        for (int j = 0; j < nums[i]; ++j) {
            cout << i;
        }
    }
    cout << endl;
    return 0;
}
