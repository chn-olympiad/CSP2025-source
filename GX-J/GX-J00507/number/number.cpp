#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> n;

bool compare(int a, int b) {
    return (a > b);
}

int main () {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;
    for (auto c: s) {
        if (c < '0' || c > '9')
            continue;
        n.push_back(c - '0');
    }
    sort(n.begin(), n.end(), compare);
    for (auto i: n) {
        cout << i;
    }
    cout << endl;
    return 0;
}