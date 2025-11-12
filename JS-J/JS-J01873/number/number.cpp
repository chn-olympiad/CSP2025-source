#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
string s;
priority_queue<char> q;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (char ch : s) if (isdigit(ch)) q.push(ch);
    while (!q.empty()) cout << q.top(), q.pop();
    cout << '\n';
    return 0;
}
// expect 100pts