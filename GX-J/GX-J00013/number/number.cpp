#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(!isdigit(s[i])) {
            s.erase(i, 1);
            i--;
        }
    }
    sort(s.begin(), s.end(), [](char a, char b) {
         return a > b;
         });
    cout << s;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
