#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
int a[N], la;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9')
           a[++la] = s[i] - '0';
    }
    sort(a + 1, a + la + 1, cmp);
    for (int i = 1; i <= la; i++)
        printf("%d", a[i]);
    printf("\n");
    return 0;
}
