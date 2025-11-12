#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(char a, char b) {
    return a > b;
}

string s;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            cout << s[i];
        }
    }
    return 0;
}
