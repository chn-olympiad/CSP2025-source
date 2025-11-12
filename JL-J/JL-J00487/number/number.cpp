#include <bits/stdc++.h>
using namespace std;
bool cmp(char a, char b) {
    return ((a - '0') > (b - '0'));
}
int main() {
    string s;
    int ni = 0;
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    char x[s.length()];
    for (int j = 0 ; j < s.length() ; j++) {
        char i = s[j];
        if (i == '0' || i == '1' || i == '2' || i == '3' || i == '4' || i == '5' || i == '6' || i == '7' || i == '8' || i == '9') {
            x[ni] = i;
            ni++;
        }
    }
    sort(x, x + ni + 1, cmp);
    for (int i = 0 ; i <= ni ; i++) {
        char j = x[i];
        if (j == '0' || j == '1' || j == '2' || j == '3' || j == '4' || j == '5' || j == '6' || j == '7' || j == '8' || j == '9') {
            cout << j;
        }
    }
    cout << endl;
    return 0;
}