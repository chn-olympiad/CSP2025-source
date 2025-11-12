#include <bits/stdc++.h>
using namespace std;
char c;
string s;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    while (scanf("%c", &c) != EOF) {
        if (isdigit(c)) {
            s.push_back(c);
        }
    }
    sort(s.begin(), s.end(), greater<>());
    cout << s << "\n";
    return 0;
}