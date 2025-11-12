#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000005];
int cnt;
bool cmd(int x, int y) {
    return x > y;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[cnt] = s[i] - '0';
            cnt++;
        }
    }
    sort(a, a + cnt + 1, cmd);

    for (int i = 0; i < cnt; i++) {
        cout << a[i];
    }
    return 0;
}
//g++ number.cpp -o number.exe;./number.exe