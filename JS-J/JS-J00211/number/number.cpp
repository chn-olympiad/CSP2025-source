#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
char s[N];
int a[N] = {};
int cnt = 1;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s);
    for (char c : s)
        if (isdigit(c))
            a[cnt++] = c - '0';
    sort (a + 1, a + cnt);
    for (int i = cnt - 1; i >= 1; --i)
        cout << a[i];
    return 0;
}
