#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
string s;
int r;
char num[N];

bool cmp(char a, char b) {
    return a > b;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "W", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num[r++] = s[i];
        }
    }

    sort(num, num + r, cmp);

    for (int i = 0; i < r; i++) {
        cout << num[i];
    }
    return 0;
}
