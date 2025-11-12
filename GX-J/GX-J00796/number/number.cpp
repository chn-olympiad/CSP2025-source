#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

string s, ans;

bool isnum(char c) {
    return c >= '0' && c <= '9' ? true : false;
}

bool cmp(char a, char b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isnum(s[i])) {
            ans += s[i];
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans;
    return 0;
}
