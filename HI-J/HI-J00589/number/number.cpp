#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
#ifndef LOCAL
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
#endif

    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    string s;
    cin >> s;
    array<int, 10> a{};
    for(auto c: s) {
        if(isdigit(c)) {
            a[c - '0']++;
        }
    }

    for(int i = 9; i >= 0; i--) {
        for(int j = 1; j <= a[i]; j++) {
            cout << i;
        }
    }
    cout << '\n';


    return 0;
}
// 8:38