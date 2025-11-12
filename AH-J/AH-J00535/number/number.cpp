#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
string s;
int a[M];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int num = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3') {
            num ++;
            a[num] = s[i] - '0';
        }
        else if (s[i] == '4' || s[i] == '5' || s[i] == '6') {
            num ++;
            a[num] = s[i] - '0';
        }
        else if (s[i] == '7' || s[i] == '8' || s[i] == '9') {
            num ++;
            a[num] = s[i] - '0';
        }
    }
    sort(a + 1, a + num + 1);
    for (int i = num; i >= 1; i --) cout << a[i];
    return 0;
}
