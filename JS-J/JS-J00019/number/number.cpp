#include <bits/stdc++.h>
using namespace std;
string s;
int n[1000005], i;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
        if (s[j] <= '9' && s[j] >= '0') {
            n[++i] = s[j] - '0';
        }
    }
    sort(n + 1, n + i + 1);
    for (int j = i; j >= 1; --j) printf("%d", n[j]);
    return 0;
}
