#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, temp = "";
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if ((s[i] >= '0' && s[i] <= '9')) {
            temp += s[i];
        }
    }
    sort(temp.begin(), temp.end(), greater<char>());
    cout << temp;
    return 0;
}
