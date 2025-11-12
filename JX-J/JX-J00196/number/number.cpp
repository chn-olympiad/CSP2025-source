#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 5;

string s;
int a[MAX_N];

int main () {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);

    cin >> s;
    int len = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[len] = s[i] - '0';
            len++;
        }
    }
    sort (a + 1, a + len);
    for (int i = len - 1; i >= 1; i--) {
        cout << a[i];
    }
	return 0;
}
