#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000006];

bool cmp (int a, int b) {
    return a > b;
}

int main () {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);


    cin >> s;

    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        if ('0' <= s[i] and s[i] <= '9') {
            a[j] = int(s[i]) - int('0');
            j++;
        }
    }

    sort(a, a + j, cmp);

    for (int i = 0; i < j; i++) {
        cout << a[i];
    }

    return 0;
}
