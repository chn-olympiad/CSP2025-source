# include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            q.push(c - '0');
        }
    }
    while (!q.empty()) {
        int p = q.top();
        q.pop();
        printf("%d", p);
    }
    return 0;
}
