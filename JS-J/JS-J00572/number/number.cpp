#include<bits/stdc++.h>
using namespace std;
int a[105];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    // s 仅包含小写英文字母及数字,且包含至少一个 1 ∼ 9 中的数字
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int x = s[i] - '0';
            a[x]++;
        }
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 1; j <= a[i]; j++) cout << i;
    }
    return 0;
}