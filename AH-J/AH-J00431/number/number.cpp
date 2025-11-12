#include <bits/stdc++.h>
using namespace std;

string s;
string ret;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            ret += s[i];
        }
    }
    sort(ret.begin(), ret.end());
    for (int i = ret.size() - 1; i >= 0; i--) {
        printf("%c", ret[i]);
    }
    return 0;
}

// Problem creater, I will praise you in the future.
// Find_Light!
