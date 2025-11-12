#include <bits/stdc++.h>
using namespace std;
string s, ans;
bool cmp(char a, char b) {
	return a > b;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            ans += s[i];
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans;
    return 0;
}
