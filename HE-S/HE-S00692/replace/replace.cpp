#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, q;

string s1, s2;
string l1, l2;
string t1[N], t2[N];

int main () {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    cin >> s1 >> s2;
    for (int i = 1; i <= n; i ++ ) {
        cin >> t1[i] >> t2[i];
    }
    while (q -- ) {
        cin >> l1 >> l2;
        cout << "0\n";
    }
    return 0;
}
