#include <bits/stdc++.h>

using namespace std;

vector<int> a;

bool px(int x, int y) {
    return x > y;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    getline(cin, s);

    int len = s.size();
    for (int i = 0;i < len;i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a.push_back(s[i] - '0');
        }
    }

    sort(a.begin(), a.end(), px);

    //sc
    for (int i = 0;i < a.size();i++) {
        cout << a[i];
    }

    return 0;
}
