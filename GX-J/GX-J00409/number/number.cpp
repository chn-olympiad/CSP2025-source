#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    vector<int> vec;
    cin >> s;

    for (char c: s) {
        if ('0' <= c && c <= '9') vec.push_back(c - '0');
    }

    sort(vec.begin(), vec.end(), [](int l, int r){ return l > r; });

    for (int v: vec) {
        cout << v;
    }
    cout << endl;

    return 0;
}