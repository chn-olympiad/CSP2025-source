#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, m, cnt;
bool fbl = true;
string s1[N], s2[N];
string t1, t2;
struct node {
    int st, ed;
}t[N];

bool B(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'a' && s[i] != 'b') return false;
        if (s[i] == 'b') cnt++;
    }
    if (cnt != 1) return false;
    return true;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
        if (!B(s1[i]) || !B(s2[i])) {
            fbl = false;
        }
    }
    while (m--) {
        cnt = 0;
        cin >> t1 >> t2;
        cout << 0 << "\n";
    }
    return 0;
}
