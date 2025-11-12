#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN]; int idx = 0;
bool cmp(int a, int b)  {
    return a > b;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    char c = getchar();
    while (c != EOF && c != '\n' && c != ' ') {
        if (isdigit(c)) a[++idx] = c - '0';
        c = getchar();
    }
    sort(a + 1, a + idx + 1, cmp);
    for (int i = 1; i <= idx; ++i) cout << a[i];
    return 0;
}