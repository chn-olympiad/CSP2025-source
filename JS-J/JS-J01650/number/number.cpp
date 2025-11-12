#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> nums;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if ((int)s[i] >= 48 && (int)s[i] <= 57)
            nums.push_back((int)s[i] - 48);
    }
    sort(nums.rbegin(), nums.rend());
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    return 0;
}
