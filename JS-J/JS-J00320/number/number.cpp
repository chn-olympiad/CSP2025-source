#include <bits/stdc++.h>
using namespace std;
const int N = 1E6 + 10;
int a[N], cnt;
bool cmp(int a, int b) {return a > b;}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            a[++cnt] = s[i] - '0';
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++) {
        cout << a[i];
    }
    return 0;
}
//#Shang4Shan3Ruo6Shui4
//last year it is poker
//this year it is number
