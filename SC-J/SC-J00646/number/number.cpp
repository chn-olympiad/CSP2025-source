#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int a[N], cnt;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s; cin >> s;
    for(int i = 0; i < (int)s.size(); i++) 
        if('0' <= s[i] && s[i] <= '9')
            a[++cnt] = s[i] - '0';
    sort(a + 1, a + cnt + 1);
    for(int i = cnt; i >= 1; i--)
        printf("%d", a[i]);
    printf("\n");
}