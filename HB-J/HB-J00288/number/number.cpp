#include <bits/stdc++.h>
using namespace std;

string s;

bool cmp(char a, char b) {
    return a > b;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    string str;
    for (char c : s) {
        if ('0' <= c && c <= '9') str += c;
    }
    sort(str.begin(), str.end(), cmp);
    cout << str;
    return 0;
}
