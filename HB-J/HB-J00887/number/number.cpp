#include <bits/stdc++.h>
using namespace std;
string s, result;
bool cmp(char a, char b) {
    return a > b ? true : false;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (char c : s) {
        if (c >= '0' and c <= '9') result.push_back(c);
    }
    sort(result.begin(), result.end(), cmp);
    cout << result;
    return 0;
}
