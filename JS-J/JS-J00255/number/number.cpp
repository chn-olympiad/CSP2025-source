#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int a[1000010];
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') a[++n] = (s[i] - '0');
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    return 0;
}
//freopen 怎么拼啊？
// 堵桥来
