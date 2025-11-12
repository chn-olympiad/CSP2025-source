#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string get;
    int cnt[10];
    memset(cnt, 0x00, sizeof(cnt));
    getline(cin, get);
    for (char c : get)
        if ('0' <= c && c <= '9')
            cnt[c - '0']++;
    for (int i = 9; i >= 0; i--)
        while (cnt[i]--)
            putchar('0' + i);
    return 0;
}
