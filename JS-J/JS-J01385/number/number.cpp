#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    int len = s.size();
    vector<int> num;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            num.push_back(s[i] - '0');
        }
    }
    sort(num.begin(), num.end(), greater<int>());
    int nlen = num.size();
    for (int i = 0; i < nlen; i++) {
        cout << num[i];
    }

    return 0;
}
