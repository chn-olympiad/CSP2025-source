#include <bits/stdc++.h>

using namespace std;

string s;
priority_queue <int> q;
//int a[1000010];
//int m;

int main () {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i ++ ) {
        if (s[i] >= '0' && s[i] <= '9') q.push(s[i] - '0');
        // if (s[i] >= '0' && s[i] <= '9') a[++m] = s[i] - '0';
    }
    while (q.size()) {
        printf("%d", q.top());
        q.pop();
    }
    //sort (a + 1, a +1 +m);
    //for (int i = m; i >= 1; i -- ) printf("%d", a[i]);
    return 0;
}
