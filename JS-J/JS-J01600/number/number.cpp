#include <bits/stdc++.h>
using namespace std;
//number
int num[1000001];

bool is_num(char c) {
    return ('0' <= c && c <= '9');
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int cur = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (is_num(s[i])) {
            num[++cur] = s[i] - '0';
        }
    }
    sort(num + 1, num + 1 + cur, [](int a, int b) {  return a > b;});
    for (int i = 1; i <= cur; i++) {
        cout << num[i];
    }
}
