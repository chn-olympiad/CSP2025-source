#include <iostream>
using namespace std;

int cnt[10]; char ch;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (cin >> ch)
        if (ch >= '0' && ch <= '9')
            cnt[ch - '0'] ++;
    for (int i = 9; i >= 0; i --)
        while (cnt[i] --) cout << i;
    return 0;
}
