#include<bits/stdc++.h>

using namespace std;

string s;
const int N = 1e6 + 5;
int a[N];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int len = s.size(), tot = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[++tot] = s[i] - 48;
        }
    }
    sort(a+1, a+tot+1);
    for (int i = tot; i >= 1; i--) {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
