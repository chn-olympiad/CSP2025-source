#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    getline(cin, s);
    vector<int> a;
    for (int i = 0; i < s.length(); i++) {
        if (!(s[i] <= 'z' && s[i] >= 'A')) {
            a.push_back(s[i] - 48);
        }
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
    }

    return 0;
}
