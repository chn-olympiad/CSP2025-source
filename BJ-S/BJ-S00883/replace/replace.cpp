#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int N = 2e5 + 10;

int n, q;
string s1[N], s2[N];

int main () {
    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ) {
        cin >> s1[i] >> s2[i];
    }

    while (q -- ) {
        string q1, q2;
        cin >> q1 >> q2;
        int ans = 0;
        cout << ans << endl;
    }

    return 0;
}
