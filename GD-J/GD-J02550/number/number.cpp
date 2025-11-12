#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin >> s;

    vector<int> a;
    for(auto i : s) {
        if(isdigit(i)) {
            a.push_back(i - '0');
        }
    }

    sort(a.begin(), a.end(), greater<int>());

    for(auto i : a) {
        cout << i;
    }
}