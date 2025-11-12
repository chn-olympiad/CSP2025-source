#include <bits/stdc++.h>
using namespace std;
int number_num[10] = { 0 };
long long awaawa = 0;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0 ; i < s.length() ; i++) {
        if (('0' <= s[i]) & (s[i] <= '9')) {
            number_num[s[i] - '0']++;
        }
    }
    for (int i = 9 ; i >= 0 ; i--) {
        for (int j = 0 ; j < number_num[i] ; j++) {
            cout << i;
        }
    }
    return 0;
}
