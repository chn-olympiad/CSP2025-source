#include <iostream>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.ans", "w", stdout);
    string s;
    cin >> s;
    char num[1000];
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            num[i] = s[i];
            cnt++;
        }
    }
    for (int i = 0; i < cnt - 1; i++) {
        if ((int)num[i] > (int)num[i + 1]) {
            int t = (int)num[i];
            num[i] = (int)num[i + 1];
            num[i + 1] = t;
        }
    }
    for (int i = 0; i < cnt; i++) {
        cout << (char)(num[i]);
    }
    return 0;
}
