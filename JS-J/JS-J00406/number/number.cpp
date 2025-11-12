#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> cnt(10);
    string s;
    cin >> s;
    for (char c : s)
        if (isdigit(c))
            cnt[c - '0']++;
    for (int i = 9; i >= 0; i--)
        while (cnt[i]--)
            cout << i;
    cout << '\n';
    return 0;
}