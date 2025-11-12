// number.cpp
#include <iostream>
#include <queue>
using namespace std;

string s;
priority_queue<int> p;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int len = s.size();

    for (int i = 0; i < len; i++) {
        if ('0' <= s[i] && s[i] <= '9')
            p.push(s[i] - '0');
    }

    while (!p.empty()) {
        cout << p.top();
        p.pop();
    }

    cout << '\n';
    return 0;
}
